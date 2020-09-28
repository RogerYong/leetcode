from typing import List
'''
统计逆序数
只需要修改几行代码


'''


def merge_sort_for_reverse_pair(nums, left, right):
    if not nums or left >= right:
        return []  # 如果说要打印, 那就用一个list保存即可
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
    # cnt = 0  # 逆序数对计算
    rev_pair = []

    while i <= mid and j <= right:
        if nums[i] <= nums[j]:  # 从小到大排序
            tmp.append(nums[i])
            i += 1
        else:
            tmp.append(nums[j])

            # cnt += mid - i + 1  # 逆序数对计算

            tmp_pairs = [(larger_num, nums[j])
                         for larger_num in nums[i:mid + 1]]
            rev_pair.extend(tmp_pairs)
            j += 1

    while i <= mid:
        tmp.append(nums[i])
        i += 1

    while j <= right:
        tmp.append(nums[j])
        j += 1

    nums[left:right + 1] = tmp

    # return cnt  # 逆序数对计算
    return rev_pair


class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        if not nums:
            return []
        res = merge_sort_for_reverse_pair(nums, 0, len(nums) - 1)
        res.sort()
        return res


if __name__ == "__main__":
    a = [7, 5, 6, 4]
    print(a)
    s = Solution()
    cnt = s.reversePairs(a)
    print(cnt)
    print(a)
