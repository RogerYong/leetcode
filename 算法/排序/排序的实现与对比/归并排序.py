def mergeSort(nums, left, right):
    if not nums or left >= right:
        return
    mid = (left + right) // 2
    mergeSort(nums, left, mid)  # nums[left:mid]
    mergeSort(nums, mid + 1, right)  # nums[mid+1:right]
    merge(nums, left, mid, right)


def merge(nums, left, mid, right):
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

    while i <= mid and j <= right:
        if nums[i] <= nums[j]:  # 从小到大排序
            tmp.append(nums[i])
            i += 1
        else:
            tmp.append(nums[j])
            j += 1

    while i <= mid:
        tmp.append(nums[i])
        i += 1

    while j <= right:
        tmp.append(nums[j])
        j += 1

    nums[left:right + 1] = tmp


if __name__ == "__main__":
    a = [7, 5, 6, 4]
    print(a)
    mergeSort(a, 0, len(a) - 1)
    print(a)
