#include "the0.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits.h>

void swaper(int &x, int &y)
{
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

void duzSwap(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

void ilgincSwap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void insertionSort(int *arr, long &comparison, long &swap, int size)
{

    int i = 1;
    while (i < size)
    {
        int x = arr[i];
        int j = i - 1;

        comparison++;
        while (j >= 0 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            j--;
            comparison++;
            swap++;
        }
        arr[j + 1] = x;
        i++;
    }
}

// // Function to check if an array is sorted correctly
// bool isSorted(int *arr, int size)
// {
//     for (int i = 1; i < size; i++)
//     {
//         if (arr[i] < arr[i - 1])
//         {
//             return false;
//         }
//     }
//     return true;
// }

int main()
{
    long x;

    printf("%ld\n", x);

    std::cout << x << std::endl;

    return 0;
}