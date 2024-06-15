#include "monitor.h"
#include "helper.h"
#include "WriteOutput.h"
#include "main.h"
#include <iostream>
#include <vector>
#include <pthread.h>
#include <queue>

using namespace std;

#define CALCULATE_TIMEOUT(ts, waitTime)                                      \
    do                                                                       \
    {                                                                        \
        struct timeval tv;                                                   \
        gettimeofday(&tv, NULL);                                             \
        (ts).tv_sec = tv.tv_sec + ((waitTime) / 1000);                       \
        (ts).tv_nsec = (tv.tv_usec + 1000UL * ((waitTime) % 1000)) * 1000UL; \
        if ((ts).tv_nsec >= 1000000000UL)                                    \
        {                                                                    \
            (ts).tv_nsec -= 1000000000;                                      \
            (ts).tv_sec++;                                                   \
        }                                                                    \
    } while (0)

static int ferryCounter01 = 0;
static int ferryCounter10 = 0;

class Ferry : public Monitor
{
public:
    int travelTime;
    int maxWaitTime;
    int capacity;
    int connectorId;

    int currentCapacity01;
    int currentCapacity10;

    bool timeOut10Flag = false;
    bool timeOut01Flag = false;

    Condition timeOut01; // condition variable
    Condition timeOut10; // condition variable

    Condition passTimer01; // condition variable
    Condition passTimer10; // condition variable

    Condition capacityFull01; // condition variable
    Condition capacityFull10; // condition variable

    Ferry(int travelTime, int maxWaitTime, int capacity, int id) : travelTime(travelTime), maxWaitTime(maxWaitTime),
                                                                   capacity(capacity), connectorId(id),
                                                                   currentCapacity01(0), currentCapacity10(0),
                                                                   capacityFull01(this), capacityFull10(this),
                                                                   timeOut01(this), timeOut10(this),
                                                                   passTimer01(this), passTimer10(this)
    {
    }

    void pass(int carId, int from)
    {
        __synchronized__;
        if (from == 0)
        {
            currentCapacity01++;
            if ((currentCapacity01 % capacity) == 1) // first car
            {
                struct timespec ts01;
                CALCULATE_TIMEOUT(ts01, maxWaitTime);
                timeOut01Flag = false;
                int timedWaitResult = timeOut01.timedwait(&ts01);
                if (timedWaitResult == ETIMEDOUT)
                {
                    timeOut01Flag = true; // set the flag to true
                    currentCapacity01--;
                    capacityFull01.notifyAll();
                }
                WriteOutput(carId, 'F', connectorId, Action::START_PASSING);
            }

            else if (currentCapacity01 == capacity)
            {
                if (capacity == 2)
                {
                    currentCapacity01 = 0;
                }
                WriteOutput(carId, 'F', connectorId, Action::START_PASSING);
                capacityFull01.notifyAll(); // Notify waiting cars outside the critical section
                timeOut01.notifyAll();
            }
            else
            {
                while (currentCapacity01 < capacity && !timeOut01Flag)
                {
                    capacityFull01.wait();
                }
                ferryCounter01++;
                if (ferryCounter01 == capacity - 2 && !timeOut01Flag)
                {
                    ferryCounter01 = 0;
                    currentCapacity01 -= capacity;
                }
                else
                {
                    currentCapacity01--;
                    ferryCounter01--;
                }
                WriteOutput(carId, 'F', connectorId, Action::START_PASSING);
            }

            struct timespec travelts01;
            CALCULATE_TIMEOUT(travelts01, travelTime);
            int timedWaitResult = passTimer01.timedwait(&travelts01); // Simulate travel time
            if (timedWaitResult != ETIMEDOUT)
            {
                // cout << "timer problem" << endl;
            }
            WriteOutput(carId, 'F', connectorId, Action::FINISH_PASSING);
        }
        else
        {
            currentCapacity10++;
            if ((currentCapacity10 % capacity) == 1) // first car
            {
                struct timespec ts10;
                CALCULATE_TIMEOUT(ts10, maxWaitTime);
                timeOut10Flag = false;
                int timedWaitResult = timeOut10.timedwait(&ts10);
                if (timedWaitResult == ETIMEDOUT)
                {
                    timeOut10Flag = true; // set the flag to true
                    currentCapacity10--;
                    capacityFull10.notifyAll();
                }
                WriteOutput(carId, 'F', connectorId, Action::START_PASSING);
            }

            else if (currentCapacity10 == capacity)
            {
                if (capacity == 2)
                {
                    currentCapacity10 = 0;
                }
                WriteOutput(carId, 'F', connectorId, Action::START_PASSING);
                capacityFull10.notifyAll(); // Notify waiting cars outside the critical section
                timeOut10.notifyAll();
            }
            else
            {
                while (currentCapacity10 < capacity && !timeOut10Flag)
                {

                    capacityFull10.wait();
                }
                ferryCounter10++;
                if (ferryCounter10 == capacity - 2 && !timeOut10Flag)
                {
                    ferryCounter10 = 0;
                    currentCapacity10 -= capacity;
                }
                else
                {
                    currentCapacity10--;
                    ferryCounter10--;
                }

                WriteOutput(carId, 'F', connectorId, Action::START_PASSING);
            }

            struct timespec travelts10;
            CALCULATE_TIMEOUT(travelts10, travelTime);

            int timedWaitResult = passTimer10.timedwait(&travelts10); // Simulate travel time
            if (timedWaitResult != ETIMEDOUT)
            {
                // cout << "timer 10 problem" << endl;
            }
            WriteOutput(carId, 'F', connectorId, Action::FINISH_PASSING);
        }
    }
};

class NarrowBridge : public Monitor
{
public:
    int travelTime;
    int maxWaitTime;
    int connectorId;

    int activeLane; // shows the active lane

    bool passingBridge[2]; // used in order to implement PASS_DELAY
    int waitingCount[2];   // shows the number of cars waiting in the lane
    int passingNow[2];     // shows the number of cars passing in the lane
    int laneChangeFlag[2]; // condition variable

    Condition waiting[2];         // if car is waiting in the lane
    Condition activeLaneTimer[2]; // the timer for lane change

    Condition laneCV; // wait for the lane to be changed

    Condition pass_delay;      // timer for pass delay
    Condition passTimerHelper; // helper for pass delay
    int timer_count;           // helper for pass delay

    Condition travelTimer; // timer for travel time

    queue<int> waitingCarQueue[2]; // queue for waiting cars

    NarrowBridge(int travelTime, int maxWaitTime, int id)
        : connectorId(id), travelTime(travelTime), maxWaitTime(maxWaitTime), activeLane(-1),
          waiting{this, this}, waitingCount{0, 0}, passingNow{0, 0}, timer_count(0), laneChangeFlag{0, 0},
          laneCV(this), activeLaneTimer{this, this}, passingBridge{false, false},
          pass_delay(this), travelTimer(this), passTimerHelper(this)
    {
    }

    void pass(int carId, int lane)
    {
        __synchronized__;

        // if there is no active lane, set the lane as active
        if (activeLane == -1 && lane != -1)
            activeLane = lane;

        if (lane == 0)
        {
            waitingCount[lane]++;
            // check if it is active lane wait for the lane to be changed
            while (lane != activeLane)
            {
                if (waitingCount[lane] - passingNow[lane] == 1)
                {
                laneChanged0:
                    if (laneChangeFlag[lane] == 0)
                    {
                        // if maxWait time exceed, preemption
                        struct timespec ts;
                        CALCULATE_TIMEOUT(ts, maxWaitTime);
                        int timedWaitResult = activeLaneTimer[lane].timedwait(&ts);
                        if (timedWaitResult == ETIMEDOUT)
                        {
                            activeLane = lane;
                            laneChangeFlag[lane] = 1;
                        }
                    }
                    if (activeLane == lane)
                    {
                        while (passingNow[1 - lane] != 0)
                        {
                            laneCV.wait();
                        }
                    }
                    activeLane = lane;
                    laneChangeFlag[lane] = 0;
                }
                else
                {
                    waitingCarQueue[lane].push(carId);
                    waiting[lane].wait();

                    while (waitingCarQueue[lane].front() != carId)
                    {
                        waiting[lane].wait();
                    }

                    waitingCarQueue[lane].pop();
                }
            }
            laneChangeFlag[lane] = 0;
            // at this point no car is passing in the same lane, then pass
            if (waitingCount[lane] >= 1)
            {
                // pass delay implementation
                if (passingBridge[lane] && (passingNow[lane] > 0))
                {
                    while (timer_count != 0)
                    {
                        passTimerHelper.wait();
                    }
                    timer_count++;
                    struct timespec ts;
                    CALCULATE_TIMEOUT(ts, PASS_DELAY);
                    pass_delay.timedwait(&ts);
                    timer_count--;
                    passTimerHelper.notify();
                }
                else
                {
                    passingBridge[lane] = true;
                }

                if (activeLane != lane)
                {
                    goto laneChanged0;
                }
                WriteOutput(carId, 'N', connectorId, Action::START_PASSING);
                passingNow[lane]++; // indicate that a car is passing
                waiting[lane].notifyAll();

                // sleep for travel time
                struct timespec ts;
                CALCULATE_TIMEOUT(ts, travelTime);
                travelTimer.timedwait(&ts);
                passingNow[lane]--; // release the lane
                WriteOutput(carId, 'N', connectorId, Action::FINISH_PASSING);
            }
            if (--waitingCount[lane] == 0)
            {
                laneChangeFlag[1 - lane] = 1;
                activeLaneTimer[1 - lane].notify();
            }
            if (passingNow[lane] == 0)
            {
                laneCV.notifyAll();
            }
        }
        else
        {
            waitingCount[lane]++;
            while (lane != activeLane)
            {
                if (waitingCount[lane] - passingNow[lane] == 1)
                {
                laneChanged1:
                    if (laneChangeFlag[lane] == 0)
                    {
                        struct timespec ts;
                        CALCULATE_TIMEOUT(ts, maxWaitTime);
                        int timedWaitResult = activeLaneTimer[lane].timedwait(&ts);
                        if (timedWaitResult == ETIMEDOUT)
                        {
                            activeLane = lane;
                            laneChangeFlag[lane] = 1;
                        }
                    }
                    if (activeLane == lane) // lane is active but there is a car passing in the other lane
                    {
                        while (passingNow[1 - lane] != 0)
                        {
                            laneCV.wait();
                        }
                    }
                    activeLane = lane;
                    laneChangeFlag[lane] = 0;
                }
                else
                {
                    waitingCarQueue[lane].push(carId);
                    waiting[lane].wait();

                    while (waitingCarQueue[lane].front() != carId)
                    {
                        waiting[lane].wait();
                    }
                    waitingCarQueue[lane].pop();
                }
            }
            laneChangeFlag[lane] = 0;
            // at this point no car is passing in the same lane, then pass
            if (waitingCount[lane] >= 1)
            {
                // pass delay implementation
                if (passingBridge[lane] && (passingNow[lane] > 0))
                {
                    while (timer_count != 0)
                    {
                        passTimerHelper.wait();
                    }
                    timer_count++;

                    struct timespec ts;
                    CALCULATE_TIMEOUT(ts, PASS_DELAY);
                    pass_delay.timedwait(&ts);
                    timer_count--;
                    passTimerHelper.notify();
                }
                else
                {
                    passingBridge[lane] = true;
                }
                if (activeLane != lane)
                {
                    goto laneChanged1;
                }
                WriteOutput(carId, 'N', connectorId, Action::START_PASSING);
                passingNow[lane]++;
                waiting[lane].notifyAll();

                // sleep for travel time
                struct timespec ts;
                CALCULATE_TIMEOUT(ts, travelTime);
                travelTimer.timedwait(&ts);
                passingNow[lane]--;
                WriteOutput(carId, 'N', connectorId, Action::FINISH_PASSING);
            }

            if (--waitingCount[lane] == 0)
            {
                laneChangeFlag[1 - lane] = 1;
                activeLaneTimer[1 - lane].notify();
            }
            if (passingNow[lane] == 0)
            {
                laneCV.notifyAll();
            }
        }
    }
};

class Crossroad : public Monitor
{
public:
    int travelTime;
    int maxWaitTime;
    int connectorId;

    int activeLane;

    int waitingCount[4];
    int passingNow[4];
    bool passingBridge[4];

    Condition waiting[4];

    int laneChangeFlag[4];

    Condition activeLaneTimer;

    Condition laneCV;

    Condition travelTimer;

    Condition pass_delay;
    Condition passTimerHelper;
    int timer_count;

    queue<int> waitingCarQueue[4]; // queue for waiting cars

    Crossroad(int travelTime, int maxWaitTime, int id)
        : connectorId(id), travelTime(travelTime), maxWaitTime(maxWaitTime),
          activeLane(-1), waitingCount{0, 0, 0, 0}, passingNow{0, 0, 0, 0}, waiting{this, this, this, this},
          laneChangeFlag{0, 0, 0, 0}, activeLaneTimer{this}, laneCV(this), pass_delay(this),
          passTimerHelper(this), timer_count(0), travelTimer{this}, passingBridge{false, false, false, false} {}

    void pass(int carId, int lane)
    {
        __synchronized__;
        if (activeLane == -1)
        {
            activeLane = lane;
        }
        if (lane == 0)
        {
            waitingCount[lane]++;
            while (lane != activeLane)
            {
                if (waitingCount[lane] - passingNow[lane] == 1)
                {
                laneChanged0:
                    if (laneChangeFlag[lane] == 0)
                    {
                        // if maxWait time exceed preemption
                        struct timespec ts;
                        CALCULATE_TIMEOUT(ts, maxWaitTime);
                        int timedWaitResult = activeLaneTimer.timedwait(&ts);
                        if (timedWaitResult == ETIMEDOUT)
                        {
                            int nextLaneCounter = (lane + 1) % 4;
                            while (waitingCount[nextLaneCounter] == 0 && nextLaneCounter != lane)
                            {
                                nextLaneCounter = (nextLaneCounter + 1) % 4;
                            }
                            if (nextLaneCounter == lane)
                            {
                                laneChangeFlag[lane] = 1;
                            }
                            else
                            {
                                laneChangeFlag[nextLaneCounter] = 1;
                                activeLaneTimer.notifyAll();
                            }
                        }
                        else if (!laneChangeFlag[lane])
                        {
                            goto laneChanged0;
                        }
                    }
                    if (activeLane == lane)
                    {
                        while (passingNow[(lane + 3) % 4] > 0 || passingNow[(lane + 2) % 4] > 0 || passingNow[(lane + 1) % 4] > 0)
                        {
                            laneCV.wait();
                        }
                    }

                    activeLane = lane;
                    laneChangeFlag[lane] = 0;
                }
                else
                {
                    waitingCarQueue[lane].push(carId);
                    waiting[lane].wait();

                    while (waitingCarQueue[lane].front() != carId)
                    {
                        waiting[lane].wait();
                    }
                    waitingCarQueue[lane].pop();
                }
            }
            laneChangeFlag[lane] = 0;

            if (waitingCount[lane] >= 1)
            {
                // pass delay implementation
                if (passingBridge[lane] && (passingNow[lane] > 0))
                {
                    while (timer_count != 0)
                    {
                        passTimerHelper.wait();
                    }
                    timer_count++;

                    struct timespec ts;
                    CALCULATE_TIMEOUT(ts, PASS_DELAY);
                    pass_delay.timedwait(&ts);
                    timer_count--;
                    passTimerHelper.notify();
                }
                else
                {
                    passingBridge[lane] = true;
                }
                if (activeLane != lane)
                {
                    goto laneChanged0;
                }
                WriteOutput(carId, 'C', connectorId, Action::START_PASSING);
                passingNow[lane]++;
                waiting[lane].notifyAll();
                // sleep for travel time
                struct timespec ts;
                CALCULATE_TIMEOUT(ts, travelTime);
                travelTimer.timedwait(&ts);
                passingNow[lane]--;
                WriteOutput(carId, 'C', connectorId, Action::FINISH_PASSING);
            }
            int nextLane;
            if (--waitingCount[lane] == 0)
            {
                nextLane = (lane + 1) % 4;
                while (waitingCount[nextLane] == 0 && nextLane != lane)
                {
                    nextLane = (nextLane + 1) % 4;
                }

                if (nextLane == lane)
                {
                    activeLane = -1;
                }
                else
                {
                    laneChangeFlag[nextLane] = 1;
                    activeLaneTimer.notifyAll();
                }
            }
            if (passingNow[lane] == 0)
            {
                laneCV.notifyAll();
            }
        }
        else if (lane == 1)
        {
            waitingCount[lane]++;
            while (lane != activeLane)
            {
                if (waitingCount[lane] - passingNow[lane] == 1)
                {
                laneChanged1:
                    if (laneChangeFlag[lane] == 0)
                    {
                        // if maxWait time exceed preemption
                        struct timespec ts;
                        CALCULATE_TIMEOUT(ts, maxWaitTime);
                        int timedWaitResult = activeLaneTimer.timedwait(&ts);
                        if (timedWaitResult == ETIMEDOUT)
                        {
                            int nextLaneCounter = (lane + 1) % 4;
                            while (waitingCount[nextLaneCounter] == 0 && nextLaneCounter != lane)
                            {
                                nextLaneCounter = (nextLaneCounter + 1) % 4;
                            }
                            if (nextLaneCounter == lane)
                            {
                                laneChangeFlag[lane] = 1;
                            }
                            else
                            {
                                laneChangeFlag[nextLaneCounter] = 1;
                                activeLaneTimer.notifyAll();
                            }
                        }
                        else if (!laneChangeFlag[lane])
                        {
                            goto laneChanged1;
                        }
                    }
                    if (activeLane == lane)
                    {
                        while (passingNow[(lane + 3) % 4] > 0 || passingNow[(lane + 2) % 4] > 0 || passingNow[(lane + 1) % 4] > 0)
                        {
                            laneCV.wait();
                        }
                    }
                    activeLane = lane;
                    laneChangeFlag[lane] = 0;
                }
                else
                {
                    waitingCarQueue[lane].push(carId);
                    waiting[lane].wait();

                    while (waitingCarQueue[lane].front() != carId)
                    {
                        waiting[lane].wait();
                    }
                    waitingCarQueue[lane].pop();
                }
            }

            laneChangeFlag[lane] = 0;
            if (waitingCount[lane] >= 1)
            {
                // pass delay implementation
                if (passingBridge[lane] && (passingNow[lane] > 0 > 0))
                {
                    while (timer_count != 0)
                    {
                        passTimerHelper.wait();
                    }
                    timer_count++;

                    struct timespec ts;
                    CALCULATE_TIMEOUT(ts, PASS_DELAY);
                    pass_delay.timedwait(&ts);
                    timer_count--;
                    passTimerHelper.notify();
                }
                else
                {
                    passingBridge[lane] = true;
                }

                if (activeLane != lane)
                {
                    goto laneChanged1;
                }

                WriteOutput(carId, 'C', connectorId, Action::START_PASSING);
                passingNow[lane]++;
                waiting[lane].notifyAll();
                // sleep for travel time
                struct timespec ts;
                CALCULATE_TIMEOUT(ts, travelTime);
                travelTimer.timedwait(&ts);
                passingNow[lane]--;
                WriteOutput(carId, 'C', connectorId, Action::FINISH_PASSING);
            }
            int nextLane;
            if (--waitingCount[lane] == 0)
            {
                nextLane = (lane + 1) % 4;
                while (waitingCount[nextLane] == 0 && nextLane != lane)
                {
                    nextLane = (nextLane + 1) % 4;
                }
                if (nextLane == lane)
                {
                    activeLane = -1;
                }
                else
                {
                    laneChangeFlag[nextLane] = 1;
                    activeLaneTimer.notifyAll();
                }
            }
            if (passingNow[lane] == 0)
            {
                laneCV.notifyAll();
            }
        }
        else if (lane == 2)
        {
            waitingCount[lane]++;
            while (lane != activeLane)
            {
                if (waitingCount[lane] - passingNow[lane] == 1)
                {
                laneChanged2:
                    if (laneChangeFlag[lane] == 0)
                    {
                        // if maxWait time exceed preemption
                        struct timespec ts;
                        CALCULATE_TIMEOUT(ts, maxWaitTime);
                        int timedWaitResult = activeLaneTimer.timedwait(&ts);
                        if (timedWaitResult == ETIMEDOUT)
                        {
                            int nextLaneCounter = (lane + 1) % 4;
                            while (waitingCount[nextLaneCounter] == 0 && nextLaneCounter != lane)
                            {
                                nextLaneCounter = (nextLaneCounter + 1) % 4;
                            }
                            if (nextLaneCounter == lane)
                            {
                                // activeLane = lane;
                                laneChangeFlag[lane] = 1;
                            }
                            else
                            {
                                // activeLane = nextLaneCounter;
                                laneChangeFlag[nextLaneCounter] = 1;
                                activeLaneTimer.notifyAll();
                            }
                        }
                        else if (!laneChangeFlag[lane])
                        {
                            goto laneChanged2;
                        }
                    }
                    if (activeLane == lane)
                    {
                        while (passingNow[(lane + 3) % 4] > 0 || passingNow[(lane + 2) % 4] > 0 || passingNow[(lane + 1) % 4] > 0)
                        {
                            laneCV.wait();
                        }
                    }
                    activeLane = lane;
                    laneChangeFlag[lane] = 0;
                }
                else
                {
                    waitingCarQueue[lane].push(carId);
                    waiting[lane].wait();

                    while (waitingCarQueue[lane].front() != carId)
                    {
                        waiting[lane].wait();
                    }
                    waitingCarQueue[lane].pop();
                }
            }
            laneChangeFlag[lane] = 0;

            if (waitingCount[lane] >= 1)
            {

                // pass delay implementation
                if (passingBridge[lane] && (passingNow[lane] > 0))
                {
                    while (timer_count != 0)
                    {
                        passTimerHelper.wait();
                    }
                    timer_count++;

                    struct timespec ts;
                    CALCULATE_TIMEOUT(ts, PASS_DELAY);
                    pass_delay.timedwait(&ts);
                    timer_count--;
                    passTimerHelper.notify();
                }
                else
                {
                    passingBridge[lane] = true;
                }

                if (activeLane != lane)
                {
                    goto laneChanged2;
                }
                WriteOutput(carId, 'C', connectorId, Action::START_PASSING);
                passingNow[lane]++;
                waiting[lane].notifyAll();
                // sleep for travel time
                struct timespec ts;
                CALCULATE_TIMEOUT(ts, travelTime);
                travelTimer.timedwait(&ts);
                passingNow[lane]--;
                WriteOutput(carId, 'C', connectorId, Action::FINISH_PASSING);
            }
            int nextLane;
            if (--waitingCount[lane] == 0)
            {
                nextLane = (lane + 1) % 4;
                while (waitingCount[nextLane] == 0 && nextLane != lane)
                {
                    nextLane = (nextLane + 1) % 4;
                }
                if (nextLane == lane)
                {
                    activeLane = -1;
                }
                else
                {
                    laneChangeFlag[nextLane] = 1;
                    activeLaneTimer.notifyAll();
                }
            }
            if (passingNow[lane] == 0)
            {
                laneCV.notifyAll();
            }
        }
        else if (lane == 3)
        {
            waitingCount[lane]++;
            while (lane != activeLane)
            {
                if (waitingCount[lane] - passingNow[lane] == 1)
                {
                laneChanged3:
                    if (laneChangeFlag[lane] == 0)
                    {
                        // if maxWait time exceed preemption
                        struct timespec ts;
                        CALCULATE_TIMEOUT(ts, maxWaitTime);
                        int timedWaitResult = activeLaneTimer.timedwait(&ts);
                        if (timedWaitResult == ETIMEDOUT)
                        {
                            int nextLaneCounter = (lane + 1) % 4;
                            while (waitingCount[nextLaneCounter] == 0 && nextLaneCounter != lane)
                            {
                                nextLaneCounter = (nextLaneCounter + 1) % 4;
                            }
                            if (nextLaneCounter == lane)
                            {
                                // activeLane = lane;
                                laneChangeFlag[lane] = 1;
                            }
                            else
                            {
                                // activeLane = nextLaneCounter;
                                laneChangeFlag[nextLaneCounter] = 1;
                                activeLaneTimer.notifyAll();
                            }

                            // activeLane = lane;
                            // laneChangeFlag[lane] = 1;
                        }
                        else if (!laneChangeFlag[lane])
                        {
                            goto laneChanged3;
                        }
                    }
                    if (activeLane == lane)
                    {
                        while (passingNow[(lane + 3) % 4] > 0 || passingNow[(lane + 2) % 4] > 0 || passingNow[(lane + 1) % 4] > 0)
                        {
                            laneCV.wait();
                        }
                    }
                    activeLane = lane;
                    laneChangeFlag[lane] = 0;
                }
                else
                {
                    waitingCarQueue[lane].push(carId);
                    waiting[lane].wait();

                    while (waitingCarQueue[lane].front() != carId)
                    {
                        waiting[lane].wait();
                    }
                    waitingCarQueue[lane].pop();
                }
            }
            laneChangeFlag[lane] = 0;

            if (waitingCount[lane] >= 1)
            {
                // pass delay implementation
                if (passingBridge[lane] && (passingNow[lane] > 0))
                {
                    while (timer_count != 0)
                    {
                        passTimerHelper.wait();
                    }
                    timer_count++;

                    struct timespec ts;
                    CALCULATE_TIMEOUT(ts, PASS_DELAY);
                    pass_delay.timedwait(&ts);
                    timer_count--;
                    passTimerHelper.notify();
                }
                else
                {
                    passingBridge[lane] = true;
                }
                if (activeLane != lane)
                {
                    goto laneChanged3;
                }
                WriteOutput(carId, 'C', connectorId, Action::START_PASSING);
                passingNow[lane]++;
                waiting[lane].notifyAll();
                // sleep for travel time
                struct timespec ts;
                CALCULATE_TIMEOUT(ts, travelTime);
                travelTimer.timedwait(&ts);
                passingNow[lane]--;
                WriteOutput(carId, 'C', connectorId, Action::FINISH_PASSING);
            }
            int nextLane;
            if (--waitingCount[lane] == 0)
            {
                nextLane = (lane + 1) % 4;
                while (waitingCount[nextLane] == 0 && nextLane != lane)
                {
                    nextLane = (nextLane + 1) % 4;
                }
                if (nextLane == lane)
                {
                    activeLane = -1;
                }
                else
                {
                    laneChangeFlag[nextLane] = 1;
                    activeLaneTimer.notifyAll();
                }
            }
            if (passingNow[lane] == 0)
            {
                laneCV.notifyAll();
            }
        }
    }
};

int numNarrowBridges, numFerries, numCrossroads, numCars;
vector<NarrowBridge *> narrowBridges;
vector<Ferry *> ferries;
vector<Crossroad *> crossroads;
vector<Car *> cars;

// input parser
void parseInput(int &numNarrowBridges, vector<NarrowBridge *> &narrowBridges,
                int &numFerries, vector<Ferry *> &ferries,
                int &numCrossroads, vector<Crossroad *> &crossroads,
                int &numCars, vector<Car *> &cars)
{

    cin >> numNarrowBridges;
    for (int i = 0; i < numNarrowBridges; ++i)
    {
        int travelTime, maxWaitTime;
        cin >> travelTime >> maxWaitTime;
        NarrowBridge *currentNarrowBridge = new NarrowBridge(travelTime, maxWaitTime, i);
        narrowBridges.push_back(currentNarrowBridge);
    }

    cin >> numFerries;
    for (int i = 0; i < numFerries; ++i)
    {
        int travelTime, maxWaitTime, capacity;
        cin >> travelTime >> maxWaitTime >> capacity;
        Ferry *currentFerry = new Ferry(travelTime, maxWaitTime, capacity, i);
        ferries.push_back(currentFerry);
    }

    cin >> numCrossroads;
    for (int i = 0; i < numCrossroads; ++i)
    {
        int travelTime, maxWaitTime;
        cin >> travelTime >> maxWaitTime;
        Crossroad *currentCrossroad = new Crossroad(travelTime, maxWaitTime, i);
        crossroads.push_back(currentCrossroad);
    }

    cin >> numCars;
    string connectorType;
    int from, to;
    // cars.resize(numCars);
    for (int i = 0; i < numCars; ++i)
    {
        int pathLength, travelTime;
        Car *currentCar = new Car();

        cin >> travelTime >> pathLength;
        currentCar->travelTime = travelTime;
        currentCar->pathLength = pathLength;
        // currentCar->pathList.resize(pathLength);
        for (int j = 0; j < pathLength; ++j)
        {
            cin >> connectorType >> from >> to;
            Path currentPath;
            switch (connectorType[0])
            {
            case 'N':
            {
                currentPath.connectorType = ConnectorType::NARROW_BRIDGE;
                break;
            }
            case 'F':
            {
                currentPath.connectorType = ConnectorType::FERRY;
                break;
            }
            case 'C':
            {
                currentPath.connectorType = ConnectorType::CROSSROAD;
                break;
            }
            }
            currentPath.connectorID = stoi(connectorType.substr(1));
            currentPath.direction = make_pair(from, to);
            currentCar->pathList.push_back(currentPath);
        }
        cars.push_back(currentCar);
    }
}

// car thread function
void *carThread(void *arg)
{
    int carIndex, travelTime, pathLength;
    carIndex = *((int *)arg); // car id
    Car *currentCar = cars[carIndex];
    pathLength = currentCar->pathLength;
    travelTime = currentCar->travelTime;

    for (auto &step : currentCar->pathList)
    {

        ConnectorType currentConnectorType = step.connectorType;
        int connectorID = step.connectorID;

        WriteOutput(carIndex, typeToChar(currentConnectorType), connectorID, Action::TRAVEL);
        sleep_milli(travelTime);
        WriteOutput(carIndex, typeToChar(currentConnectorType), connectorID, Action::ARRIVE);

        // Implement the behavior for each step in the path
        switch (currentConnectorType)
        {
        case ConnectorType::NARROW_BRIDGE:
        {
            narrowBridges[connectorID]->pass(carIndex, step.direction.first);
            break;
        }
        case ConnectorType::FERRY:
        {
            ferries[connectorID]->pass(carIndex, step.direction.first);
            break;
        }
        case ConnectorType::CROSSROAD:
        {
            crossroads[connectorID]->pass(carIndex, step.direction.first);
            break;
        }
        }
    }
    return NULL;
}

int main()
{
    parseInput(numNarrowBridges, narrowBridges, numFerries, ferries, numCrossroads, crossroads, numCars, cars);

    InitWriteOutput(); // Initialize WriteOutput

    vector<pthread_t> threads(numCars); // pthread_t for each car
    vector<int> carIndices(numCars);    // enumerated car indices

    for (int i = 0; i < numCars; ++i)
    {
        carIndices[i] = i;
        if (pthread_create(&threads[i], NULL, carThread, (void *)&carIndices[i]) < 0)
        {
            cout << "Error creating thread " << i << endl;
        }
    }
    for (int i = 0; i < numCars; ++i)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            cout << "Error joining thread " << i << endl;
        }
    }

    // delete all allocated memory
    for (int i = 0; i < numNarrowBridges; ++i)
    {
        delete narrowBridges[i];
    }
    for (int i = 0; i < numFerries; ++i)
    {
        delete ferries[i];
    }
    for (int i = 0; i < numCrossroads; ++i)
    {
        delete crossroads[i];
    }
    for (int i = 0; i < numCars; ++i)
    {
        delete cars[i];
    }
    return 0;
}