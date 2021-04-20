#include <bitset>
#include <vector>
#include <set>
using namespace std;
class Solution
{
private:
    // 记录三个用于检查状态的bitset
    vector<bitset<9>> isValidRow;
    vector<bitset<9>> isValidColumn;
    vector<bitset<9>> isValidBlock;
    // 以及一个可选节点的列表
    set<pair<int, int>> candidateCoor; // VIS

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        isValidRow = vector<bitset<9>>(9, bitset<9>());
        isValidColumn = vector<bitset<9>>(9, bitset<9>());
        isValidBlock = vector<bitset<9>>(9, bitset<9>());
        candidateCoor.clear();

        int row, column, block = 0;
        char tmp = 0;
        int tmp_digit = 0;
        for (row = 0; row < 9; row++)
        {
            for (column = 0; column < 9; column++)
            {
                tmp = board[row][column];
                if (tmp == '.')
                {
                    candidateCoor.insert({row, column});
                }
                else
                {
                    block = (row / 3) * 3 + column / 3; // 获取block
                    tmp_digit = tmp - '1';
                    isValidRow[row].set(tmp_digit);
                    isValidColumn[column].set(tmp_digit);
                    isValidBlock[block].set(tmp_digit);
                }
            }
        }
        // 从可选节点的优先队列中, 选取可选状态最少的下一个节点, 进行DFS
        dfs(board);
    }

    bool dfs(vector<vector<char>> &board)
    {
        // 如果已经为空, return True
        if (candidateCoor.empty())
        {
            return true;
        }
        // getNext 获取下一点
        auto pos = getNext();

        int row = pos.first;
        int column = pos.second;
        int block = (pos.first / 3) * 3 + pos.second / 3;
        auto possible = getPossibleNum(row, column);
        if (possible.count() == 0) // 不可解
        {
            return false;
        }
        // 遍历各种 可选值,DFS
        candidateCoor.erase(pos);

        for (int i = 0; i < 9; i++)
        {
            if (possible.test(i))
            {
                board[row][column] = i + '1';

                isValidRow[row].set(i);
                isValidColumn[column].set(i);
                isValidBlock[block].set(i);

                bool ans = dfs(board);
                if (ans)
                {
                    return true;
                }
                else
                {
                    // 维护状态
                    board[row][column] = '.';
                    isValidRow[row].reset(i);
                    isValidColumn[column].reset(i);
                    isValidBlock[block].reset(i);
                }
            }
        }
        candidateCoor.insert(pos); // 维护状态
        return false;
    }

    bitset<9> getPossibleNum(int row, int column)
    {
        return ~(isValidRow[row] | isValidColumn[column] | isValidBlock[(row / 3) * 3 + column / 3]);
    }

    pair<int, int> getNext()
    {
        // 通过getNext() 获取下一个可选状态更少的位置
        pair<int, int> minPos;
        int minCnt = 10;
        for (auto &c : candidateCoor)
        {
            int cnt = getPossibleNum(c.first, c.second).count();
            if (cnt < minCnt)
            {
                minCnt = cnt;
                minPos = c;
            }
        }
        return minPos;
    }
};