#include <iostream>
#include <vector>

using namespace std;

// Function to perform Needleman-Wunsch alignment
void needlemanWunsch(const string &seq1, const string &seq2, int match, int mismatch, int gap)
{
    int len_seq1 = seq1.length();
    int len_seq2 = seq2.length();

    // Initialize the score matrix with zeros
    vector<vector<int>> score_matrix(len_seq1 + 1, vector<int>(len_seq2 + 1, 0));

    // Initialize the traceback matrix
    vector<vector<char>> traceback_matrix(len_seq1 + 1, vector<char>(len_seq2 + 1, 0));

    // Initialize the first row and column of the score matrix
    for (int i = 1; i <= len_seq1; ++i)
    {
        score_matrix[i][0] = score_matrix[i - 1][0] + gap;
        traceback_matrix[i][0] = 'U';
    }

    for (int j = 1; j <= len_seq2; ++j)
    {
        score_matrix[0][j] = score_matrix[0][j - 1] + gap;
        traceback_matrix[0][j] = 'L';
    }

    // Fill in the score matrix and traceback matrix
    for (int i = 1; i <= len_seq1; ++i)
    {
        for (int j = 1; j <= len_seq2; ++j)
        {
            int match_mismatch_score = (seq1[i - 1] == seq2[j - 1]) ? match : mismatch;
            int diagonal_score = score_matrix[i - 1][j - 1] + match_mismatch_score;
            int up_score = score_matrix[i - 1][j] + gap;
            int left_score = score_matrix[i][j - 1] + gap;

            // Determine the maximum score and update the traceback matrix
            int max_score = std::max(std::max(diagonal_score, up_score), left_score);
            score_matrix[i][j] = max_score;

            if (max_score == diagonal_score)
            {
                traceback_matrix[i][j] = 'D';
            }
            else if (max_score == up_score)
            {
                traceback_matrix[i][j] = 'U';
            }
            else
            {
                traceback_matrix[i][j] = 'L';
            }
        }
    }

    // Traceback to reconstruct the alignment
    string aligned_seq1 = "";
    string aligned_seq2 = "";
    int i = len_seq1, j = len_seq2;

    while (i > 0 || j > 0)
    {
        if (traceback_matrix[i][j] == 'D')
        {
            aligned_seq1 = seq1[i - 1] + aligned_seq1;
            aligned_seq2 = seq2[j - 1] + aligned_seq2;
            --i;
            --j;
        }
        else if (traceback_matrix[i][j] == 'U')
        {
            aligned_seq1 = seq1[i - 1] + aligned_seq1;
            aligned_seq2 = '-' + aligned_seq2;
            --i;
        }
        else
        {
            aligned_seq1 = '-' + aligned_seq1;
            aligned_seq2 = seq2[j - 1] + aligned_seq2;
            --j;
        }
    }

    // Print the aligned sequences
    cout << "Sequence 1: " << aligned_seq1 << endl;
    cout << "Sequence 2: " << aligned_seq2 << endl;
}

int main()
{
    string seq1 = "CB";
    string seq2 = "CC";
    int match = 4;
    int mismatch = -2;
    int gap = -1;

    needlemanWunsch(seq1, seq2, match, mismatch, gap);

    return 0;
}
