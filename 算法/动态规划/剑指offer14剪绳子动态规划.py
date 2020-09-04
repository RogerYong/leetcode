# 动态规划中的特殊情况
#


class Solution:
    def cuttingRope(self, n: int) -> int:
        '''
        2 <= n <= 58

        剪成m段 , m>1

        不能不剪

        但是,有些情况, 不剪比剪的收益大

        x = (x/2) * (x/2)  得 x = 4, 即 x>=4时, 剪开的收益大于不剪的

        x=2,3时 不剪的收益更大

        '''
        if n < 2:
            return 0
        if n == 2:
            return 1
        if n == 3:
            return 2

        # 下面讨论>=4的情况

        # dp[i] 表示 长为i的绳子, 得到的最大乘积
        dp = [0] * (n + 1)
        dp[1] = 1  # n=1,2,3是特殊的, 不剪收益更大
        dp[2] = 2
        dp[3] = 3

        # 状态转移方程
        # dp[i] = max (dp[j] * dp[i-j])
        # 时间复杂度O(n2)
        for i in range(4, n + 1):
            for j in range(1, i):  # 对称的, 还可以进一步优化
                dp[i] = max(dp[i], dp[j] * dp[i - j])

        return dp[n]
