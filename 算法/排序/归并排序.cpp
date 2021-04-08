#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int> &nums, vector<int> &tmp, int left, int mid, int right)
{
    /*
    nums[left:mid]
    nums[mid+1:right]
    已经排好序
    */
    if (left >= right)
    {
        return;
    }
    int i = left;       // 左区间[left:mid]的下标
    int j = mid + 1;    // 左区间[mid+1:right]的下标
    int tmp_idx = left; // tmp数组的下标
    while (i <= mid && j <= right)
    {
        if (nums[i] <= nums[j]) // 从小到大排序
        {
            tmp[tmp_idx++] = nums[i++];
        }
        else
        {
            tmp[tmp_idx++] = nums[j++];
        }
    }

    while (i <= mid)
    {
        tmp[tmp_idx++] = nums[i++];
    }
    while (j <= right)
    {
        tmp[tmp_idx++] = nums[j++];
    }

    // 把临时结果copy到原数组
    tmp_idx = left;
    while (tmp_idx <= right)
    {
        nums[tmp_idx] = tmp[tmp_idx];
        tmp_idx++;
    }
}
void mergeSort(vector<int> &nums, vector<int> &tmp, int left, int right)
{
    // nums是原始数组
    // tmp是临时数组/结果数组, 避免每次递归重新开辟临时数组
    // nums.size() == tmp.size()
    // left 左下标
    // right 右下标
    if (left >= right)
    {
        return;
    }

    int mid = (left + right) / 2;
    mergeSort(nums, tmp, left, mid);      //  nums[left:mid]
    mergeSort(nums, tmp, mid + 1, right); //  nums[mid+1:right]
    merge(nums, tmp, left, mid, right);
}
void print_vector(vector<int> nums)
{
    for (auto it = nums.begin(); it != nums.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> nums{7, 5, 6, 4};
    vector<int> tmp(4);

    print_vector(nums);
    print_vector(tmp);

    mergeSort(nums, tmp, 0, nums.size() - 1);

    print_vector(nums);
    print_vector(tmp);

    return 0;
}