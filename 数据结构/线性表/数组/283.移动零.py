class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        cnt = 0
        for i in range(len(nums)):
            if nums[i]:
                nums[i-cnt], nums[i] = nums[i], nums[i-cnt]
            else:
                cnt = cnt + 1
        