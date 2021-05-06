#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> generateMatrix(int n)
    {
        if (n == 1)
        {
            return {{1}};
        }
        // 访问矩阵
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<vector<int>> ans(n, vector<int>(n, 0)); // 结果矩阵

        int cur_direction = 0; // 开始是朝右
        int cur_row = 0;
        int cur_column = 0; // 右上角开始

        for (int i = 0; i < n * n; i++)
        {
            ans[cur_row][cur_column] = i + 1;
            vis[cur_row][cur_column] = 1;

            int tmp_next_row = cur_row + directions[cur_direction][0];
            int tmp_next_column = cur_column + directions[cur_direction][1];

            if (tmp_next_row < 0 || tmp_next_row >= n || tmp_next_column < 0 || tmp_next_column >= n || vis[tmp_next_row][tmp_next_column] == 1)
            {
                cur_direction = (cur_direction + 1) % 4;
            }
            cur_row += directions[cur_direction][0];
            cur_column += directions[cur_direction][1];
        }
        return ans;
    }
};