#include <vector>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <utility>
#include <memory>
#include <iostream>
#include <chrono>

using namespace std;

void get_infection_scores(const std::vector<std::vector<std::pair<int, int>>> &network,
                          std::vector<float> &infection_scores)
{
    int n = network.size();
    unsigned distances[n][n];

    unsigned maxDistance = 0;

    // Initialize distances to infinity
    for (int i = 0; i < n; i++)
    {
        std::fill_n(distances[i], n, INT_MAX);
    }

    // initilize distances from network
    for (int i = 0; i < n; i++)
    {
        for (auto &pair : network[i])
        {
            distances[i][pair.first] = pair.second;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (distances[i][k] == INT_MAX || distances[k][j] == INT_MAX)
                {
                    continue;
                }
                // relaxation step
                if (distances[i][j] > distances[i][k] + distances[k][j])
                {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (distances[i][j] != INT_MAX && distances[i][j] > maxDistance)
            {
                maxDistance = distances[i][j];
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     distances[i][i] = 0;
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (distances[i][j] == INT_MAX)
            {
                distances[i][j] = maxDistance + 1;
            }
        }
    }

    // calculate infection scores
    for (int i = 0; i < n; i++)
    {
        float score = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                score += distances[i][j];
            }
        }
        score /= (n - 1);
        infection_scores.push_back(1.f / score);
    }
}

int main(void)
{
    // std::vector<std::vector<std::pair<int, int>>> network = {
    //     {{4, 21}, {6, 8}, {12, 16}, {13, 35}, {14, 1}, {16, 27}, {22, 49}, {23, 35}, {24, 46}, {28, 29}},
    //     {{3, 3}, {4, 49}, {6, 20}, {8, 23}, {9, 23}, {10, 26}, {11, 42}, {15, 47}, {17, 30}, {19, 46}, {23, 40}, {27, 48}},
    //     {{7, 12}, {14, 28}, {15, 24}, {16, 42}, {20, 37}, {21, 7}, {23, 1}, {25, 42}, {26, 43}, {29, 27}},
    //     {{4, 25}, {11, 19}, {14, 11}, {19, 8}, {22, 11}, {25, 30}, {29, 21}},
    //     {{5, 1}, {7, 16}, {9, 40}, {14, 37}, {15, 35}, {16, 30}, {19, 18}, {21, 24}, {25, 23}, {27, 26}, {28, 11}},
    //     {{10, 48}, {12, 5}, {13, 20}, {14, 25}, {18, 35}, {20, 2}, {21, 47}, {22, 17}, {23, 17}, {28, 5}},
    //     {{8, 23}, {10, 11}, {17, 30}, {18, 48}, {19, 34}, {22, 40}, {23, 17}, {24, 40}, {25, 15}, {27, 24}, {28, 44}},
    //     {{8, 7}, {13, 5}, {15, 11}, {17, 22}, {18, 35}, {23, 40}, {24, 21}, {27, 23}, {28, 21}},
    //     {{9, 9}, {14, 7}, {15, 8}, {17, 39}, {19, 23}, {22, 11}, {27, 27}, {29, 27}},
    //     {{13, 42}, {14, 6}, {15, 27}, {20, 25}, {26, 33}},
    //     {{11, 3}, {14, 21}, {18, 31}, {25, 32}},
    //     {{13, 13}, {15, 37}, {16, 42}, {19, 42}, {24, 41}, {27, 5}, {29, 21}},
    //     {{13, 23}, {14, 3}, {18, 5}, {22, 12}, {23, 8}, {24, 34}, {28, 29}, {29, 22}},
    //     {{17, 2}, {18, 24}, {19, 8}, {20, 28}},
    //     {{18, 37}, {22, 15}, {24, 40}, {29, 7}},
    //     {{16, 23}, {17, 47}, {19, 37}, {21, 31}, {23, 5}, {24, 50}, {29, 19}},
    //     {{18, 20}, {19, 26}, {22, 24}, {23, 47}, {24, 46}, {26, 21}, {29, 31}},
    //     {{18, 50}, {22, 36}, {28, 27}},
    //     {{19, 41}, {24, 24}, {25, 40}},
    //     {{20, 28}, {22, 9}, {23, 47}, {24, 21}, {25, 47}},
    //     {{25, 9}, {29, 50}},
    //     {{22, 3}},
    //     {{26, 45}},
    //     {{25, 11}, {26, 2}, {27, 45}, {28, 20}},
    //     {{27, 18}},
    //     {{28, 35}, {29, 46}},
    //     {{27, 30}},
    //     {{28, 8}}};

    // std::vector<std::vector<std::pair<int, int>>> network = {
    //     {{6, 12}, {5, 11}},
    //     {{0, 8}, {7, 2}, {4, 6}},
    //     {{3, 5}},
    //     {{4, 7}, {9, 14}, {6, 4}},
    //     {{7, 7}},
    //     {{2, 7}, {6, 4}},
    //     {},
    //     {{6, 3}},
    //     {{9, 1}, {3, 2}},
    //     {{0, 10}, {1, 9}, {3, 15}}
    // };

    std::vector<std::vector<std::pair<int, int>>> network = {
        {},
        {{0, 4}, {2, 3}},
        {{1, 5}}};

    std::vector<float> infection_scores;

    // set timer chrono
    auto start = std::chrono::high_resolution_clock::now();

    get_infection_scores(network, infection_scores);

    // end timer
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;

    std::cout << "Elapsed time: " << elapsed.count() << " s\n";

    for (auto &score : infection_scores)
    {
        std::cout << score << std::endl;
    }
    return 0;
}
