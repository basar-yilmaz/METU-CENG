#include <iostream>
#include <vector>
#include <climits>

int max3(int a, int b, int c)
{
    return std::max(std::max(a, b), c);
}

int matchMismatch(char a, char b, int match, int mismatch)
{
    return (a == b) ? match : -mismatch;
}

int recursive_alignment_helper(const std::string &sequence_A, const std::string &sequence_B,
                               int i, int j, int gap, int mismatch, int match, std::string &alignment)
{
    // Base cases
    if (i == 0 && j == 0)
    {
        return 0;
    }
    else if (i == 0)
    {
        alignment = (sequence_A[i] != sequence_B[j - 1]) ? '_' + alignment : '.' + alignment;
        return recursive_alignment_helper(sequence_A, sequence_B, i, j - 1, gap, mismatch, match, alignment) - gap;
    }
    else if (j == 0)
    {
        alignment = (sequence_A[i - 1] != sequence_B[j]) ? '.' + alignment : '_' + alignment;
        return recursive_alignment_helper(sequence_A, sequence_B, i - 1, j, gap, mismatch, match, alignment) - gap;
    }

    // Recursive calls
    int matchScore = recursive_alignment_helper(sequence_A, sequence_B, i - 1, j - 1, gap, mismatch, match, alignment);
    int gapAScore = recursive_alignment_helper(sequence_A, sequence_B, i - 1, j, gap, mismatch, match, alignment) - gap;
    int gapBScore = recursive_alignment_helper(sequence_A, sequence_B, i, j - 1, gap, mismatch, match, alignment) - gap;

    // Calculate scores for the current position
    int score = max3(matchScore, gapAScore, gapBScore);

    // Update alignment based on the maximum score
    if (score == matchScore)
    {
        alignment = sequence_A[i - 1] + alignment;
    }
    else if (score == gapAScore)
    {
        alignment = (sequence_A[i - 1] != sequence_B[j]) ? '.' + alignment : '_' + alignment;
    }
    else
    {
        alignment = (sequence_A[i] != sequence_B[j - 1]) ? '_' + alignment : '.' + alignment;
    }

    return score + matchMismatch(sequence_A[i - 1], sequence_B[j - 1], match, mismatch);
}

int recursive_alignment(const std::string &sequence_A, const std::string &sequence_B,
                        int gap, int mismatch, int match, std::string &alignment)
{
    int m = sequence_A.length();
    int n = sequence_B.length();

    return recursive_alignment_helper(sequence_A, sequence_B, m, n, gap, mismatch, match, alignment);
}

int longest_common_subsequence(const std::string &sequence_A, const std::string &sequence_B, int gap, int mismatch, int match, std::string &lcs)
{
    int m = sequence_A.length();
    int n = sequence_B.length();

    // Create a 2D vector to store the lengths of the common subsequences
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Fill the dp table using bottom-up dynamic programming
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (sequence_A[i - 1] == sequence_B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + match;
            }
            else
            {
                dp[i][j] = max3(dp[i - 1][j] - gap, dp[i][j - 1] - gap, dp[i - 1][j - 1] - mismatch);
                dp[i][j] = std::max(dp[i][j], 0); // Ensure that negative scores are treated as zero
            }
        }
    }

    // Reconstruct the longest common subsequence by backtracking through the dp table
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (sequence_A[i - 1] == sequence_B[j - 1])
        {
            lcs = sequence_A[i - 1] + lcs;
            --i;
            --j;
        }
        else
        {
            if (dp[i][j] == dp[i - 1][j] - gap)
            {
                lcs = '_' + lcs;
                --i;
            }
            else if (dp[i][j] == dp[i][j - 1] - gap)
            {
                lcs = '!' + lcs;
                --j;
            }
            else
            {
                lcs = '!' + lcs; // In case of a mismatch
                --i;
                --j;
            }
        }
    }

    // Handle remaining characters
    while (i > 0)
    {
        lcs = '_' + lcs;
        --i;
    }

    while (j > 0)
    {
        lcs = '!' + lcs;
        --j;
    }

    return dp[m][n]; // Return the length of the longest common subsequence
}

int main()
{
    std::string sequence_A = "ACD";
    std::string sequence_B = "ABCD";
    int gap = 1;
    int mismatch = 2;
    int match = 4;

    std::string alignment;
    int score = recursive_alignment(sequence_A, sequence_B, gap, mismatch, match, alignment);

    std::cout << "Recursive Alignment Score: " << score << std::endl;
    std::cout << "Alignment: " << alignment << std::endl;

    return 0;
}