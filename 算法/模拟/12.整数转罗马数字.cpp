#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<vector<string>> table = {
            {"", "M", "MM", "MMM"},                                       //千位
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, // 百位
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, // 十位
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}  // 个位
        };

        int thousand = num / 1000;
        int hundred = (num % 1000) / 100;
        int ten = (num % 100) / 10;
        int one = num % 10;
        string res = table[0][thousand] + table[1][hundred] + table[2][ten] + table[3][one];
        return res;
    }
};