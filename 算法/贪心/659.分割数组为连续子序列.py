'''
解法1: 贪心法把当前数字添加到已有的序列中, Hash + 最小堆,  时间O(nlogn), 空间O(n)

从1->n遍历有序数组

前面划分的结果保存为result, 结果中一个序列的结尾为y,长度为k, 表示为(y,k)

假设nums[i]为x

假设result中存在(x-1,k0), (x-1, k1), ...

一个贪心的选择是把当前的x添加到某一个最短的序列中

为什么?!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

因为要保证每个子序列的长度至少为3,

那就要保证最短的那个至少为3
'''
from typing import List

import heapq


class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        if not nums or len(nums) < 3:
            return False

        result = dict()  # 以key结尾的序列
        result[nums[0]] = [1]  # 序列的长度

        for i in range(1, len(nums)):
            x = nums[i]
            x_1 = x - 1
            if result.get(x_1):
                len_x_1 = heapq.heappop(result[x_1])
                len_x = len_x_1 + 1
            else:
                len_x = 1
            x_res = result.get(x, [])
            heapq.heappush(x_res, len_x)
            result[x] = x_res

        # 遍历result, 如果存在<3的
        for x, res_x in result.items():
            if len(res_x) > 0 and res_x[0] < 3:
                return False
        return True


if __name__ == "__main__":
    s = Solution()

    cases = [([1, 2, 3, 3, 4, 5], True), ([1, 2, 3, 3, 4, 4, 5, 5], True),
             ([1, 2, 3, 4, 4, 5], False)]

    for c, re in cases:
        res = s.isPossible(c)
        print('{}{}{}'.format(re, '==' if re == res else '!=', res))
