#include <vector>
#include <map>
#include <bitset>
using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<bitset<9>> isValidRow(9, bitset<9>());
        vector<bitset<9>> isValidColumn(9, bitset<9>());
        vector<bitset<9>> isValidBlock(9, bitset<9>());
        int row, column, block = 0;
        char tmp = 0;
        int tmp_digit = 0;
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
                tmp_digit = tmp - '1';
                if (isValidRow[row].test(tmp_digit) == 0 && isValidColumn[column].test(tmp_digit) == 0 &&
                    isValidBlock[block].test(tmp_digit) == 0)
                {
                    isValidRow[row].set(tmp_digit);
                    isValidColumn[column].set(tmp_digit);
                    isValidBlock[block].set(tmp_digit);
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