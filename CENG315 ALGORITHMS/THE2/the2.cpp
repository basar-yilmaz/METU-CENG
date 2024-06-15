#include <iostream>
#include <string>

char indexChar(const std::string &str, int pos)
{
    if (pos < static_cast<int>(str.length()))
    {
        char c = str.at(pos);
        return c;
    }
    else
    {
        return 'A'; // handling different size of strings
    }
}

int countingSortByDigit(std::string arr[], int size, int pos, bool ascending)
{
    const int k = 26; // ('A':65 to 'Z':90)
    int *count = new int[k];
    int iterations = 0;

    for (int i = 0; i < k; ++i)
    {
        count[i] = 0;
    }

    // Fill the count array
    for (int i = 0; i < size; ++i)
    {
        count[indexChar(arr[i], pos) - 'A']++;
        iterations++;
    }

    // Stack the count array
    for (int i = 1; i < k; i++)
    {
        count[i] += count[i - 1];
        iterations++;
    }

    std::string output[size];

    for (int i = size - 1; i >= 0; i--)
    {
        char curr = indexChar(arr[i], pos);
        int index = count[curr - 'A'] - 1;

        output[index] = arr[i];

        count[curr - 'A']--;
        iterations++;
    }

    // Copy the output array back to the original array
    for (int i = 0; i < size; i++)
    {
        if (!ascending && pos == 0)
            arr[i] = output[size - i - 1];
        else
            arr[i] = output[i];
        iterations++;
    }

    delete[] count;
    return iterations;
}

int radix_string_sort(std::string *arr, int size, bool ascending)
{
    int maxLen = 0;
    for (int i = 0; i < size; i++)
    {
        int len = arr[i].length();
        if (len > maxLen)
            maxLen = len;
    }

    int iterations = 0;
    for (int pos = maxLen - 1; pos >= 0; pos--)
    {
        iterations += countingSortByDigit(arr, size, pos, ascending) + 1;
    }
    return iterations;
}

int main()
{
    const int size = 4;
    std::string arr[size] = {"ALHAJOTH",
                             "ALGOL",
                             "ARCTURUS",
                             "ASTERION"};

    // unsorted
    std::cout << "Unsorted array: {";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i];
        if (i < size - 1)
            std::cout << ", ";
    }

    // Sorting in ascending order
    int ascendingIterations = radix_string_sort(arr, size, false);

    // Display sorted array and iterations
    std::cout << "}\nSorted array (ascending order): {";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i];
        if (i < size - 1)
            std::cout << ", ";
    }
    std::cout << "}\n";
    std::cout << "Number of iterations: " << ascendingIterations << "\n";

    return 0;
}
