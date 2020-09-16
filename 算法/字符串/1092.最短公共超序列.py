'''
https://leetcode-cn.com/problems/shortest-common-supersequence/
'''
'''
DP

'''


class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:

        if not str1:
            return str2

        if not str2:
            return str1

        len1 = len(str1)
        len2 = len(str2)

        dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]
        # dp[i][j] 表示  str1[1~i] 和 str2[1~j] 的最短公共父串的长度, 下标从1开始
        # dp[i][0] = i
        # dp[0][j] = j
        # 初始化
        dp[0][0] = 0
        for i in range(1, len1 + 1):
            dp[i][0] = i
        for j in range(1, len2 + 1):
            dp[0][j] = j

        for i in range(1, len1 + 1):
            for j in range(1, len2 + 1):
                if str1[i - 1] == str2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1

        # 回溯构建最短公共超序列
        i = len1
        j = len2
        str3 = ''
        while i > 0 and j > 0:
            if str1[i - 1] == str2[j - 1] and dp[i][j] == dp[i - 1][j - 1] + 1:
                str3 = str1[i - 1] + str3
                i -= 1
                j -= 1
            elif str1[i - 1] != str2[j - 1] and dp[i][j] == dp[i - 1][j] + 1:
                str3 = str1[i - 1] + str3
                i -= 1
            # elif str1[i - 1] != str2[j - 1] and dp[i][j] == dp[i][j - 1] + 1:
            else:
                str3 = str2[j - 1] + str3
                j -= 1

        # 多出的字符串
        while i > 0:
            str3 = str1[i - 1] + str3
            i -= 1
        while j > 0:
            str3 = str2[j - 1] + str3
            j -= 1

        return str3


def main():
    s = Solution()
    res = s.shortestCommonSupersequence('0', '1')
    print(res)


if __name__ == "__main__":
    main()
