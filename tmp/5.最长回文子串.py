#
# @lc app=leetcode.cn id=5 lang=python3
#
# [5] 最长回文子串
#


# @lc code=start
class Solution:
    def reverse(self, s: str, idx: int):
        return s[len(s) - 1 - idx]

    def longestPalindrome(self, s: str) -> str:
        str1 = s
        str2 = list(reversed(s))
        str_len = len(s)

        max_len_sub = []
        


# @lc code=end
