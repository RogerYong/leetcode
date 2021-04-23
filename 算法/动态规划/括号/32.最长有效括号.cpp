#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        if (s.size() <= 1)
        {
            return 0;
        }
        // s.size() >= 0
        vector<int> dp(s.size(), 0); // dp[i] 以i结尾的有效子串长度
        int maxLen = 0;

        // 转移方程,
        // if s[i] == '(', dp[i] = 0
        // if s[i] == ')',
        //          if s[i-1] == '(',  dp[i] = 2 + dp[i-2]
        //          if s[i-1] == ')'   && (i - 1 - dp[i - 1] >=0)
        //                      if s[ i-1 - dp[i-1] ] == '(',  dp[i] = dp[i-1] + 2 + dp[i- 2 - dp[i-1]]
        //                      if s[ i-1 - dp[i-1] ] == ')',  dp[i] = 0

        if (s[0] == '(' && s[1] == ')')
        {
            dp[1] = 2;
            maxLen = 2;
        }
        for (int i = 2; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    dp[i] = 2 + dp[i - 2];
                    maxLen = max(dp[i], maxLen);
                }
                else if (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(')
                {
                    if (i - 2 - dp[i - 1] >= 0)
                    {
                        dp[i] = dp[i - 1] + 2 + dp[i - 2 - dp[i - 1]];
                    }
                    else
                    {
                        dp[i] = dp[i - 1] + 2;
                    }
                    maxLen = max(dp[i], maxLen);
                }
            }
        }

        return maxLen;
    }
};

int main()
{
    Solution s;
    string ss = "()(())";
    s.longestValidParentheses(ss);
    return 0;
}