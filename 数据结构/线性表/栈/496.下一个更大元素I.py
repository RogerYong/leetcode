from typing import List
'''
暴力法: O(n2)

单调栈: 对于这种递减关系的数组,可以优化时间复杂度

下标从0到n, 复杂度O(n)

求右边第一个更大值: 维护一个单调递减的栈
求左边下一个更大值: 递增的栈

右边第一个更小值: 递增栈
左边第一个更小值: 递减栈

'''


class Solution:
    def nextGreaterElement(self, nums1: List[int],
                           nums2: List[int]) -> List[int]:
        stack = []
        next_greater_dict = {}
        for value in nums2:
            while len(stack) > 0 and value > stack[-1]:
                next_greater_dict[stack[-1]] = value
                stack.pop(-1)
            stack.append(value)

        for value in stack:
            next_greater_dict[value] = -1  # 没有更大的数

        result = [next_greater_dict[num] for num in nums1]
        return result
