#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (p.size() == 0)
        {
            return s.size() == 0;
        }

        // 字符串可能为空, Pattern不为空
        // dp[i][j]: 长度为i的s, 与长度为j的pat是否匹配
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));
        dp[0][0] = 1; // 两个空字符串是可以匹配
        // i=0
        for (int j = 1; j <= p.size(); j++)
        {
            dp[0][j] = (p[j - 1] == '*' && dp[0][j - 1]);
        }

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++) // 长度
            {
                if (p[j - 1] == '?' || p[j - 1] == s[i - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

int main()
{

    string s = "aa";
    string p = "*";
    Solution so = Solution();
    cout << so.isMatch(s, p) << endl;
    return 0;
}