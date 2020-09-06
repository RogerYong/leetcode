'''
腾讯2021 算法岗第二场笔试 第一题



找最长子序列: 长2k, 前k个数, 严格递减, 后k个数严格递增, 且第k个数和第k+1个数相等




另一道题:
https://leetcode.com/problems/longest-mountain-in-array/description/


'''


def longest_down(nums):
    if not nums:
        return 0
    dp = [1] * len(nums)
    for i in range(len(nums)):
        for j in range(i):
            if nums[i] < nums[j]:
                dp[i] = max(dp[i], dp[j] + 1)
    return dp


T = int(input())

for i in range(T):
    n = int(input())  #
    array = [int(_) for _ in input().strip().split()]

    array_reverse = array.copy()
    array_reverse.reverse()

    dp1 = longest_down(array)  # dp[i] 以i结尾的最长递减子序列

    dp2 = longest_down(array_reverse)

    dp2.reverse()  # 反转回来 dp[i] 从i开始的最长递增子序列

    index = {}  # 相同数字的index

    for idx, val in enumerate(array):
        tmp_l = index.get(val, [])
        tmp_l.append(idx)
        index[val] = tmp_l

    max_len = 0
    for k, v in index.items():
        # k是数字
        if len(v) >= 2:
            v.sort()
            for i in range(len(v) - 1):

                max_len = max(max_len, min(dp1[v[i]], dp2[v[i + 1]]) * 2)

    print(max_len)
