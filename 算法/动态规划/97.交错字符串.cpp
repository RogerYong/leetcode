#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if (len1 + len2 != len3)
        {
            return false;
        }
        // dp[i,j] 表示 s1[0:i) s2[0:j) 能否组成s3[0:i+j)
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        dp[0][0] = 1;

        // DP
        for (int i = 0; i <= len1; i++)
        {
            for (int j = 0; j <= len2; j++)
            {
                if (i > 0)
                {
                    dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                }
                if (j > 0)
                {
                    dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }
        return dp[len1][len2];
    }
};