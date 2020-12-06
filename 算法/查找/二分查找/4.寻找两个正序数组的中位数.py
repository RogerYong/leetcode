'''
双指针
二分法: O(log(m+n))

奇数: 找 第(m+n)/2和(m+n+2)/2

转换为: 两个数组中找第k个数
'''
from typing import List
def get_kth(nums1, nums2, k):
    '''
    k是从1开始的
    '''
    len1 = len(nums1)
    len2 = len(nums2)

    '''
    保证最多只有一个数组是空的
    '''

    if len1 == 0:
        return nums2[k-1]
    if len2 == 0:
        return nums1[k-1]
    
    if k == 1:
        return min(nums1[0], nums2[0])

    # 避免越界
    idx1 = min(len1, k//2) -1 
    idx2 = min(len2, k//2) - 1

    if nums1[idx1] <= nums2[idx2]:
        return get_kth(nums1[idx1+1:], nums2, k - (idx1+1))

    else:
        return get_kth(nums1, nums2[idx2+1:], k - (idx2+1))
    

class Solution:

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        len1 = len(nums1)
        len2 = len(nums2)

        '''
        k从1开始, 合并奇数偶数
        '''
        k1 = (len1 + len2+1)// 2
        k2 = (len1 + len2+2) // 2

        return (get_kth(nums1, nums2, k1)+get_kth(nums1, nums2, k2)) * 0.5

if __name__ == "__main__":
    cases = [
       ([1,3], [2], 2.00000),
       ([1,2], [3,4],2.50000),
       ([0,0], [0,0],0.00000),
       ([], [1], 1.00000),
       ([2],[],2.00000)
    ]
    s = Solution()
    for n1, n2, ans in cases:
        res =s.findMedianSortedArrays(n1,n2)
        print(ans,res)