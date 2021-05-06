#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        if (matrix.size() <= 1)
        {
            return;
        }

        int n = matrix.size();
        int half = n / 2;
        int tmp;
        int row1, row2, row3, row4;
        int col1, col2, col3, col4;
        for (int i = 0; i < half; i++)
        {
            // 从外往里
            for (int j = 0; j < n - i * 2 - 1; j++)
            {
                row1 = i;
                col1 = i + j;

                row2 = i + j;
                col2 = n - i - 1;

                row3 = n - i - 1;
                col3 = n - i - 1 - j;

                row4 = n - i - 1 - j;
                col4 = i;

                tmp = matrix[row4][col4];
                matrix[row4][col4] = matrix[row3][col3];
                matrix[row3][col3] = matrix[row2][col2];
                matrix[row2][col2] = matrix[row1][col1];
                matrix[row1][col1] = tmp;
            }
        }
    }
};