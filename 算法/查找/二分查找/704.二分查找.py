# 二分查找

from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid  # 找到了
            elif nums[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
        return -1