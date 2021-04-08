#include <vector>
#include <string>
using namespace std;

// 1 <= n <= 9
// 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
// 递归回溯 时间复杂度O(n!) 空间复杂度O(n)
class Solution
{
public:
    int totalNQueens(int n)
    {
        return solveNQueens(n).size();
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        dfs(result, board, 0);

        return result;
    }

    void dfs(vector<vector<string>> &result, vector<string> &board, int column)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            bool valid = check(board, i, column);
            if (valid)
            {
                board[i][column] = 'Q';

                if (column == board.size() - 1)
                {
                    result.push_back(board);
                }
                else
                {
                    dfs(result, board, column + 1);
                }
                board[i][column] = '.';
            }
        }
    }

    bool check(vector<string> &board, int row, int column)
    {

        // 检查行
        for (int j = column - 1; j >= 0; --j)
        {
            if (board[row][j] == 'Q')
            {
                return false;
            }
        }

        // 检查左上角
        for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }
        // 检查左下角
        for (int i = row + 1, j = column - 1; i < board.size() && j >= 0; ++i, --j)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
};