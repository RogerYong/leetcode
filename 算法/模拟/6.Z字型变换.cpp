#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (s.size() < 1 || numRows <= 1)
        {
            return s;
        }
        vector<string> rows(numRows, string());
        int cycle = 2 * numRows - 2;
        int cur_row;
        for (int i = 0; i < s.size(); i++)
        {
            int no_cycle = i % cycle;

            if (no_cycle < numRows)
            {
                cur_row = no_cycle;
            }
            else
            {
                cur_row = cycle -no_cycle;
            }
            rows[cur_row] += s[i];
        }

        string result = "";
        for (string &r : rows)
        {
            result += r;
        }
        return result;
    }
};

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;
    Solution ss = Solution();
    cout << ss.convert(s, numRows);
    return 0;
}