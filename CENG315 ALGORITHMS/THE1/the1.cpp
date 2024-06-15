#include <iostream>
#include <cmath>

using namespace std;

// classical way of partitioning
int partitionLomuto(unsigned short *arr, int low, int high, long &swap, double &avg_dist, double &max_dist)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] >= pivot)
        {
            std::swap(arr[++i], arr[j]);
            swap++;

            double curr_distance = std::abs(i - j);
            avg_dist += curr_distance;

            max_dist = fmax(max_dist, curr_distance);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    swap++;

    avg_dist += std::abs(i + 1 - high);
    max_dist = fmax(max_dist, std::abs(i + 1 - high));

    return (i + 1);
}

int partitionHoare(unsigned short *arr, int low, int high, long &swap, double &avg_dist, double &max_dist)
{
    int mid = low + (high - low) / 2;
    int pivot = arr[mid];
    int i = low - 1;
    int j = high + 1;
    while (true)
    {
        do
        {
            j--;
        } while (arr[j] < pivot);

        do
        {
            i++;
        } while (arr[i] > pivot);

        if (i < j)
        {

            std::swap(arr[i], arr[j]);

            swap++;
            avg_dist += std::abs(i - j);
            max_dist = fmax(max_dist, std::abs(i - j));
        }
        else
        {
            return j;
        }
    }
}

int median3(unsigned short *arr, int low, int high)
{
    int mid = low + (high - low) / 2;

    if (arr[low] > arr[mid])
    {
        if (arr[low] > arr[high])
        {
            if (arr[mid] > arr[high])
                return mid;
            else
                return high;
        }
        else
            return low;
    }
    else
    {
        if (arr[mid] > arr[high])
        {
            if (arr[low] > arr[high])
                return low;
            else
                return high;
        }
        else
            return mid;
    }
}

int quickSortHelper(unsigned short *arr, long &swap, double &avg_dist, double &max_dist, bool hoare, bool median_of_3, int low, int high);

int quickSort(unsigned short *arr, long &swap, double &avg_dist, double &max_dist, bool hoare, bool median_of_3, int size)
{
    int res = quickSortHelper(arr, swap, avg_dist, max_dist, hoare, median_of_3, 0, size - 1);
    if (swap == 0)
    {
        avg_dist = 0;
    }
    else
    {
        avg_dist = avg_dist / swap;
    }
    return res;
}

int quickSortHelper(unsigned short *arr, long &swap, double &avg_dist, double &max_dist, bool hoare, bool median_of_3, int low, int high)
{
    if (low < high)
    {
        int pivotIndex, leftCalls, rightCalls;
        if (hoare)
        {
            if (median_of_3)
            {
                int medianIndex = median3(arr, low, high);

                if (medianIndex != (low + (high - low) / 2) &&
                    arr[medianIndex] > arr[low + (high - low) / 2] &&
                    high - low > 1)
                {
                    std::swap(arr[medianIndex], arr[low + (high - low) / 2]);
                    swap++;
                    avg_dist += std::abs(medianIndex - (low + (high - low) / 2));
                    max_dist = fmax(max_dist, std::abs(medianIndex - (low + (high - low) / 2)));
                }
            }

            pivotIndex = partitionHoare(arr, low, high, swap, avg_dist, max_dist);

            leftCalls = quickSortHelper(arr, swap, avg_dist, max_dist, hoare, median_of_3, low, pivotIndex);
            rightCalls = quickSortHelper(arr, swap, avg_dist, max_dist, hoare, median_of_3, pivotIndex + 1, high);
        }
        else
        {
            if (median_of_3)
            {
                int medianIndex = median3(arr, low, high);
                if (medianIndex != high &&
                    arr[medianIndex] != arr[high] &&
                    high - low > 1)
                {
                    std::swap(arr[medianIndex], arr[high]);
                    swap++;

                    avg_dist += std::abs(medianIndex - high);
                    max_dist = fmax(max_dist, std::abs(medianIndex - high));
                }
            }

            pivotIndex = partitionLomuto(arr, low, high, swap, avg_dist, max_dist);

            leftCalls = quickSortHelper(arr, swap, avg_dist, max_dist, hoare, median_of_3, low, pivotIndex - 1);
            rightCalls = quickSortHelper(arr, swap, avg_dist, max_dist, hoare, median_of_3, pivotIndex + 1, high);
        }

        return 1 + leftCalls + rightCalls;
    }
    return 1;
}

int main()
{
    int size = 4;
    unsigned short arr[] = {1, 2, 3, 4};

    long swap = 0;
    double avg_dist = 0;
    double max_dist = 0;

    bool hoare = false;
    bool median_of_3 = false;

    std::cout << "Initial Array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    int recursiveCalls = quickSort(arr, swap, avg_dist, max_dist, hoare, median_of_3, size);

    std::cout << "Sorted Array: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    std::cout << "3 Median Lomuto Partitioning -> swap=" << swap << ", avg_dist=" << avg_dist / swap << ", max_dist=" << max_dist << ", n_calls=" << recursiveCalls << "\n";

    swap = 0;
    avg_dist = 0;
    max_dist = 0;
    recursiveCalls = 0;
    median_of_3 = false;
    unsigned short arr2[] = {1, 2, 3, 4};

    hoare = true; // Classical Hoare Partitioning
    recursiveCalls = quickSort(arr2, swap, avg_dist, max_dist, hoare, median_of_3, size);

    avg_dist = avg_dist / swap;
    if (swap == 0)
    {
        avg_dist = 0;
    }

    std::cout << "3 Median Hoare Partitioning -> swap=" << swap << ", avg_dist=" << avg_dist << ", max_dist=" << max_dist << ", n_calls=" << recursiveCalls << "\n";

    swap = 0;
    avg_dist = 0;
    max_dist = 0;

    unsigned short arr3[] = {1, 2, 3, 4};

    hoare = false;      // Classical Lomuto Partitioning
    median_of_3 = true; // Median of 3
    recursiveCalls = quickSort(arr3, swap, avg_dist, max_dist, hoare, median_of_3, size);

    std::cout << "Median of 3 Lomuto Partitioning -> swap=" << swap << ", avg_dist=" << avg_dist / swap << ", max_dist=" << max_dist << ", n_calls=" << recursiveCalls << "\n";

    swap = 0;
    avg_dist = 0;
    max_dist = 0;
    unsigned short arr4[] = {1, 2, 3, 4};
    hoare = true;       // Classical Hoare Partitioning
    median_of_3 = true; // Median of 3
    recursiveCalls = quickSort(arr4, swap, avg_dist, max_dist, hoare, median_of_3, size);

    std::cout << "Median of 3 Hoare Partitioning -> swap=" << swap << ", avg_dist=" << avg_dist / swap << ", max_dist=" << max_dist << ", n_calls=" << recursiveCalls << "\n";

    return 0;
}
