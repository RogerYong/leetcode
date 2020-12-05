/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    int reverse(string s, int idx)
    {
        return s[s.length() - 1 - idx];
    }
    string longestPalindrome(string s)
    {
        int slength = s.length();

        //
        int lenPalindrome[slength][slength] = {0};

        int path[slength][slength] = {0};

        // 初始化第0行
        for (int i = 0; i < slength; i++)
        {
            if (i == 0)
            {
                if (s[0] == reverse(s, 0))
                {
                    lenPalindrome[0][0] = 1;
                    
                }
            }
        }

        // 初始化第0列
        for (int i = 0; i < slength; i++)
        {
        }
    }
};
// @lc code=end
