'''
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个
'''

from typing import List


def complete_backpack(capacity, costs):
    '''
    完全背包+组合数

    n: 物品数
    capacity: 背包总容量
    costs: N个物品的占据的空间
    '''
    n = len(costs)
    dp = [0] * (capacity + 1)  # 初始化dp矩阵
    dp[0] = 1  # 组成容量0的情况, 设为1

    for i in range(n):  # 0到n-1
        for j in range(costs[i], capacity + 1):  # 完全背包从小到大
            dp[j] = dp[j] + dp[j - costs[i]]

    return dp[capacity]


class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        if amount == 0:
            return 1

        if amount < 0 or not coins:
            return 0

        return complete_backpack(amount, coins)
