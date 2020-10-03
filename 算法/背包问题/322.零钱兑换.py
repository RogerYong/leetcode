from typing import List

import math


def complete_backpack_full(n, capacity, costs):
    '''
    完全背包+能否装满背包

    n: 物品数
    capacity: 背包总容量
    costs: N个物品的占据的空间
    '''
    # 求最小值,所以是正无穷
    dp = [math.inf] * (capacity + 1)  # 初始化dp矩阵
    dp[0] = 0  # 容量0

    for i in range(n):  # 0到n-1
        for j in range(costs[i], capacity + 1):  # 完全背包从小到大
            dp[j] = min(dp[j], dp[j - costs[i]] + 1)

    return dp[capacity]


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        if not coins:
            return -1
        ans = complete_backpack_full(len(coins), amount, coins)
        if ans == math.inf:
            return -1
        else:
            return ans


if __name__ == "__main__":
    s = Solution()
    coins = [1, 2, 5]
    amount = 11
    s.coinChange(coins, amount)
