#include <vector>
#include <map>
#include <set>
using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<set<char>> isValueRow(9, set<char>());
        vector<set<char>> isValueColumn(9, set<char>());
        vector<set<char>> isValueBlock(9, set<char>());
        int row, column, block = 0;
        char tmp = 0;
        for (row = 0; row < 9; row++)
        {
            for (column = 0; column < 9; column++)
            {
                block = (row / 3) * 3 + column / 3;
                tmp = board[row][column];
                if (tmp == '.')
                {
                    continue;
                }
                if (isValueRow[row].count(tmp) == 0 && isValueColumn[column].count(tmp) == 0 && isValueBlock[block].count(tmp) == 0)
                {
                    isValueRow[row].insert(tmp);
                    isValueColumn[column].insert(tmp);
                    isValueBlock[block].insert(tmp);
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};