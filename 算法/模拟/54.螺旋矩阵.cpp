#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return {};
        }
        int num_rows = matrix.size();
        int num_columns = matrix[0].size();
        // 访问矩阵
        vector<vector<int>> vis(num_rows, vector<int>(num_columns, 0));

        int cur_direction = 0; // 开始是朝右
        int cur_row = 0;
        int cur_column = 0; // 右上角开始

        vector<int> ans;
        for (int i = 0; i < num_rows * num_columns; i++)
        {
            ans.push_back(matrix[cur_row][cur_column]);
            vis[cur_row][cur_column] = 1;

            int tmp_next_row = cur_row + directions[cur_direction][0];
            int tmp_next_column = cur_column + directions[cur_direction][1];

            if (tmp_next_row < 0 || tmp_next_row >= num_rows || tmp_next_column < 0 || tmp_next_column >= num_columns || vis[tmp_next_row][tmp_next_column] == 1)
            {
                cur_direction = (cur_direction + 1) % 4;
            }
            cur_row += directions[cur_direction][0];
            cur_column += directions[cur_direction][1];
        }
        return ans;
    }
};
int main()
{
}