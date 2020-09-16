'''
动态规划


'''


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        if not text1 or not text2:
            return 0

        len1 = len(text1)
        len2 = len(text2)

        # dp[i][j]表示text1[:i] 和 text2[:j]的最长公共子序列的长度
        # dp = [[0] * (len2 + 1) for _ in range(len1 + 1)]
        path = [[''] * (len2 + 1) for _ in range(len1 + 1)]  # 可用于打印

        for i in range(1, len1 + 1):
            for j in range(1, len2 + 1):
                if text1[i - 1] == text2[j - 1]:
                    # dp[i][j] = dp[i - 1][j - 1] + 1
                    path[i][j] = path[i - 1][j - 1] + text1[i - 1]
                else:
                    # dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
                    if len(path[i - 1][j]) > len(path[i][j - 1]):
                        path[i][j] = path[i - 1][j]
                    else:
                        path[i][j] = path[i][j - 1]

        # return dp[len1][len2]
        return path[len1][len2]


def main():
    s = Solution()
    s1 = '100010101010101'
    s2 = '01010001110001010000001111'
    print(s.longestCommonSubsequence(s1, s2))


if __name__ == "__main__":
    main()
