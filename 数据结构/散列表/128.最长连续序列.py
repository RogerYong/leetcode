class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if nums is None or len(nums) == 0 :
            return 0
        vis = set(nums)
        longest = 0
        for num in vis:
            if num - 1 in vis:
                # 为什么要加这一行?
                # 如果不加这行, 倒序的用例,时间复杂度会变成O(n^2)
                continue
            cur_num = num
            consecutive = 1
            while cur_num + 1 in vis:
                consecutive = consecutive + 1
                cur_num = cur_num + 1
            
            longest = max(longest, consecutive)
        return longest
            
            
             