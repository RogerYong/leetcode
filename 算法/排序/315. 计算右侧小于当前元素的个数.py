from typing import List


def merge_sort_and_cnt(nums, idxs, tmp, cnt, left, right):
    if not nums or left >= right:
        return
    mid = (left + right) // 2
    merge_sort_and_cnt(nums, idxs, tmp, cnt, left, mid)  # nums[left:mid]
    # nums[mid+1:right]
    merge_sort_and_cnt(nums, idxs, tmp, cnt, mid + 1, right)
    merge_and_cnt(nums, idxs, tmp, cnt, left, mid, right)


def merge_and_cnt(nums, idxs, tmp, cnt, left, mid, right):
    '''
    idxs[left:mid]
    idxs[mid+1:right]
    已经排好序

    进行合并
    '''
    if left >= right:
        return

    i = left
    j = mid + 1
    tmp_idx = left

    while i <= mid and j <= right:
        if nums[idxs[i]] <= nums[idxs[j]]:  # 从小到大排序
            tmp[tmp_idx] = idxs[i]
            tmp_idx += 1
            i += 1
        else:
            tmp[tmp_idx] = idxs[j]
            tmp_idx += 1
            j += 1
            for idx in idxs[i:mid + 1]:
                cnt[idx] += 1

    while i <= mid:
        tmp[tmp_idx] = idxs[i]
        tmp_idx += 1
        i += 1

    while j <= right:
        tmp[tmp_idx] = idxs[j]
        tmp_idx += 1
        j += 1

    idxs[left:right + 1] = tmp[left:right + 1]


class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        if not nums:
            return []

        idxs = list(range(len(nums)))  # 索引数组, 节省内存
        tmp = idxs.copy()  # 临时数组, 减少内存分配, 优化时间/内存
        cnt = [0] * len(nums)  # 统计

        merge_sort_and_cnt(nums, idxs, tmp, cnt, 0, len(nums) - 1)
        return cnt


if __name__ == "__main__":
    s = Solution()
    a = [5, 2, 6, 1]
    cnt = s.countSmaller(a)
    print(cnt)
