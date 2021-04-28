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
    pair<int, int> expandAroundCenter(const string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s)
    {
        if (s.size() < 1)
        {
            return s;
        }
        // 中心扩展法
        int left = 0, right = 0;
        for (int i = 0; i < s.size(); i++)
        {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > right - left)
            {
                right = right1;
                left = left1;
            }
            if (right2 - left2 > right - left)
            {
                right = right2;
                left = left2;
            }
        }
        return s.substr(left, right - left + 1);
    }
};
