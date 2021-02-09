'''
滑动窗口法
'''

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        max_len  = 1
        exist_char = []
        for c in s:
            if c in exist_char:
                exist_char = exist_char[exist_char.index(c)+1:]
                exist_char.append(c)
            else:
                exist_char.append(c)
                max_len = max (max_len, len(exist_char))

        return max_len


if __name__ == "__main__":
    cases = [
       ("abcabcbb", 3),
       ("bbbbb", 1),
       ("pwwkew",3),
       ("",0),
       ("dvdf",3)
    ]
    sl = Solution()
    for s, ans in cases:
        res =sl.lengthOfLongestSubstring(s)
        print(ans==res)