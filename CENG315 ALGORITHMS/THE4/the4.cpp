#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// print 2d array

int divide_land(int X, int Y, bool **possible_plots)
{
    std::vector<int> dp((X + 1) * (Y + 1), 0);

    for (int i = 1; i <= X; i++)
    {
        for (int j = 1; j <= Y; j++)
        {
            int temp31 = 0, temp61 = 0;

            for (int horizontal = 1; horizontal <= i; horizontal++)
            {
                int tmp = dp[(i - horizontal) * (Y + 1) + j] + dp[horizontal * (Y + 1) + j];
                temp31 = tmp > temp31 ? tmp : temp31;
            }

            for (int vertical = 1; vertical <= j; vertical++)
            {
                int tmp = dp[i * (Y + 1) + (j - vertical)] + dp[i * (Y + 1) + vertical];
                temp61 = tmp > temp61 ? tmp : temp61;
            }

            if (possible_plots[i][j])
            {
                dp[i * (Y + 1) + j] = std::max(i * j, std::max(temp31, temp61));
            }
            else
            {
                dp[i * (Y + 1) + j] = std::max(temp31, temp61);
            }
        }
    }

    return X * Y - dp[X * (Y + 1) + Y];
}

// print 2D array

int main()
{
    // Example 1
    int X1 = 9, Y1 = 12;
    bool **possible_plots1 = new bool *[X1 + 1];
    for (int i = 0; i <= X1; ++i)
    {
        possible_plots1[i] = new bool[Y1 + 1]{false};
    }
    possible_plots1[1][12] = true;
    possible_plots1[2][6] = true;
    possible_plots1[3][4] = true;
    possible_plots1[4][3] = true;
    possible_plots1[6][2] = true;

    cout << "Example 1: " << divide_land(X1, Y1, possible_plots1) << " m^2 of unused land" << endl;

    // Example 2
    int X2 = 11, Y2 = 7;
    bool **possible_plots2 = new bool *[X2 + 1];
    for (int i = 0; i <= X2; ++i)
    {
        possible_plots2[i] = new bool[Y2 + 1]{false};
    }
    possible_plots2[4][5] = true;
    possible_plots2[6][7] = true;

    cout << "Example 2: " << divide_land(X2, Y2, possible_plots2) << " m^2 of unused land" << endl;

    // Don't forget to free the allocated memory
    for (int i = 0; i <= X1; ++i)
    {
        delete[] possible_plots1[i];
    }
    delete[] possible_plots1;

    for (int i = 0; i <= X2; ++i)
    {
        delete[] possible_plots2[i];
    }
    delete[] possible_plots2;

    return 0;
}
