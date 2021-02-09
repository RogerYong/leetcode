from typing import List
'''
统计逆序数
只需要修改几行代码


'''


def merge_sort_for_reverse_pair(nums, left, right):
    if not nums or left >= right:
        return 0
    mid = (left + right) // 2
    left_reverse_pair = merge_sort_for_reverse_pair(nums, left,
                                                    mid)  # nums[left:mid]
    right_reverse_pair = merge_sort_for_reverse_pair(
        nums, mid + 1, right)  # nums[mid+1:right]
    merge_left_reverse_pair = merge_and_cnt(nums, left, mid, right)

    return left_reverse_pair + right_reverse_pair + merge_left_reverse_pair


def merge_and_cnt(nums, left, mid, right):
    '''
    nums[left:mid]
    nums[mid+1:right]
    已经排好序

    进行合并
    '''

    if left >= right:
        return

    tmp = []  # 临时数组

    i = left
    j = mid + 1
    cnt = 0  # 逆序数对计算

    while i <= mid and j <= right:
        if nums[i] <= nums[j]:  # 从小到大排序
            tmp.append(nums[i])
            i += 1
        else:
            tmp.append(nums[j])
            j += 1

            cnt += mid - i + 1  # 逆序数对计算

    while i <= mid:
        tmp.append(nums[i])
        i += 1

    while j <= right:
        tmp.append(nums[j])
        j += 1

    nums[left:right + 1] = tmp

    return cnt  # 逆序数对计算


class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        if not nums:
            return 0
        return merge_sort_for_reverse_pair(nums, 0, len(nums) - 1)


if __name__ == "__main__":
    a = [7, 5, 6, 4]
    print(a)
    s = Solution()
    cnt = s.reversePairs(a)
    print(cnt)
    print(a)
