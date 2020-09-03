from typing import List


class Solution:
    def minArray(self, numbers: List[int]) -> int:
        if not numbers:
            return None

        if len(numbers) == 1:
            return numbers[0]

        left = 0
        right = len(numbers) - 1
        while left < right:
            mid = left + (right - left) // 2
            if numbers[mid] < numbers[right]:
                right = mid
            elif numbers[mid] > numbers[right]:
                left = mid + 1  # 这是不会越界的
            else:
                # 无法判断在哪里
                right = right - 1

        return numbers[left]
