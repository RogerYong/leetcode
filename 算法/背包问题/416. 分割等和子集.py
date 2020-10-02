'''
恰好装满背包
'''
from typing import List

import math


def zero_one_backpack(n, capacity, costs, weights):
    '''
    01背包

    n: 物品数
    capacity: 背包总容量
    costs: N个物品的占据的空间
    weights: N个物品的收益
    '''
    dp = [0] * (capacity + 1)  # 初始化dp矩阵, i从0开始

    for i in range(n):  # 0到n-1
        for j in range(capacity, costs[i] - 1, -1):
            dp[j] = max(dp[j], dp[j - costs[i]] + weights[i])

    return dp[capacity]


def zero_one_backpack_opt(n, capacity, costs, weights):
    '''
    01背包, 通过cost_sums以空间换时间, 获得常数优化

    n: 物品数
    capacity: 背包总容量
    costs: N个物品的占据的空间
    weights: N个物品的收益
    cost_sums[i]: 表示costs[i:]的和
    '''
    dp = [0] * (capacity + 1)  # 初始化dp矩阵, i从0开始

    ####
    # 以空间换时间, 常数优化
    cost_sums = [0] * n
    cost_sums[n - 1] = costs[n - 1]

    for i in range(n - 2, -1, -1):
        cost_sums[i] = cost_sums[i + 1] + costs[i]
    ####

    for i in range(n):  # 0到n-1
        for j in range(capacity,
                       max(capacity - cost_sums[i], costs[i]) - 1, -1):
            dp[j] = max(dp[j], dp[j - costs[i]] + weights[i])

    return dp[capacity]


def zero_one_backpack_full(n, capacity, costs):
    '''
    能否装满背包

    n: 物品数
    capacity: 背包总容量
    costs: N个物品的占据的空间
    '''
    dp = [-math.inf] * (capacity + 1)  # 初始化dp矩阵
    dp[0] = 0  # 容量0

    for i in range(n):  # 0到n-1
        for j in range(capacity, costs[i] - 1, -1):
            dp[j] = max(dp[j], dp[j - costs[i]])

    return dp[capacity]


def zero_one_backpack_full_opt(n, capacity, costs):
    '''
    能否装满背包

    n: 物品数
    capacity: 背包总容量
    costs: N个物品的占据的空间
    cost_sums[i]: 表示costs[i:]的和
    '''
    dp = [-math.inf] * (capacity + 1)  # 初始化dp矩阵
    dp[0] = 0  # 容量0

    ####
    # 以空间换时间, 常数优化
    cost_sums = [0] * n
    cost_sums[n - 1] = costs[n - 1]

    for i in range(n - 2, -1, -1):
        cost_sums[i] = cost_sums[i + 1] + costs[i]
    ####

    for i in range(n):  # 0到n-1
        for j in range(capacity,
                       max(capacity - cost_sums[i], costs[i]) - 1, -1):
            dp[j] = max(dp[j], dp[j - costs[i]])

    return dp[capacity]


def zero_one_backpack_full_max_weights(n, capacity, costs, weights):
    '''
    装满背包且收益最大

    n: 物品数
    capacity: 背包总容量
    costs: N个物品的占据的空间
    weights: N个物品的收益
    cost_sums[i]: 表示costs[i:]的和
    '''
    dp = [-math.inf] * (capacity + 1)  # 初始化dp矩阵
    dp[0] = 0  # 容量0

    ####
    # 以空间换时间, 常数优化
    cost_sums = [0] * n
    cost_sums[n - 1] = costs[n - 1]

    for i in range(n - 2, -1, -1):
        cost_sums[i] = cost_sums[i + 1] + costs[i]
    ####

    for i in range(n):  # 0到n-1
        for j in range(capacity,
                       max(capacity - cost_sums[i], costs[i]) - 1, -1):
            dp[j] = max(dp[j], dp[j - costs[i]] + weights[i])

    return dp[capacity]


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if not nums:
            return False

        n = len(nums)

        sums = sum(nums)

        if sums % 2 == 1:
            return False

        capacity = sums // 2

        result = zero_one_backpack_full(n, capacity, nums)

        return result >= 0


if __name__ == "__main__":
    nums = [1, 5, 11, 5]
    s = Solution()
    res = s.canPartition(nums)
    print(res)
