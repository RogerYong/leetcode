'''
恰好装满背包
'''
from typing import List

import math


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
