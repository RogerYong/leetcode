#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    int match(const char &c, const string &p)
    {
        // 一个c匹配一个p
        return p[0] == '.' || c == p[0];
    }

    bool isMatch(string s, string p)
    {
        if (p.size() == 0)
        {
            return s.size() == 0;
        }
        // p.size() != 0
        vector<string> pat;
        for (int i = 0; i < p.size();)
        {
            if (i == p.size() - 1 || p[i + 1] != '*')
            {
                pat.push_back(string(1, p[i]));
                i++;
            }
            else //  p[i + 1] == '*'
            {
                pat.push_back(p.substr(i, 2));
                i += 2;
            }
        }

        // 字符串可能为空, Pattern不为空
        // dp[i][j]: 长度为i的s, 与长度为j的pat是否匹配
        vector<vector<int>> dp(s.size() + 1, vector<int>(pat.size() + 1, 0));
        dp[0][0] = 1; // 两个空字符串是可以匹配

        // i=0
        for (int j = 1; j <= pat.size(); j++)
        {
            dp[0][j] = pat[j - 1].size() == 2 && dp[0][j - 1];
        }

        for (int i = 1; i <= s.size(); i++) //
        {
            for (int j = 1; j <= pat.size(); j++) // 长度
            {
                if (pat[j - 1].size() == 2) // *
                {
                    if (match(s[i - 1], pat[j - 1]))
                    {
                        dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = dp[i][j - 1];
                    }
                }
                else
                {
                    dp[i][j] = match(s[i - 1], pat[j - 1]) && dp[i - 1][j - 1];
                }
            }
        }
        return dp[s.size()][pat.size()];
    }
};

int main()
{

    string s = "aab";
    string p = "c*a*b*";
    Solution so = Solution();
    cout << so.isMatch(s, p) << endl;
}