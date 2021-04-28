#include <vector>
#include <queue>
using namespace std;

int coors[4][2] = {
    {0, -1},
    {-1, 0},
    {0, 1},
    {1, 0},
};

class Solution
{
public:
    vector<vector<char>> &g;
    int num_row;
    int num_column;
    bool legal(int i, int j)
    {
        // 下标合法, 且没有访问过
        return (i >= 0 && i < num_row && j >= 0 && j < num_column && g[i][j] == 'l');
    }
    void bfs(int i, int j)
    {

    }
    int numIslands(vector<vector<char>> &grid)
    {
        num_row = grid.size();
        if (num_row < 1)
        {
            return 0;
        }
        num_column = grid[0].size();
        if (num_column < 1)
        {
            return 0;
        }

        g = grid;
        // BFS + 修改原数组作为 VIS数组
        for(int i=0;i<num_row)
    }
};