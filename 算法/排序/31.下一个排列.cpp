#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        // 从后往前找 顺序对

        // 找末尾的单调递减的区间
        int i = nums.size() - 2;
        for (; i >= 0 && nums[i] >= nums[i + 1]; i--)
        {
        }

        // 循环退出条件i < 0  or nums[i] < nums[i+1]

        if (i < 0)
        {
            // 表示该数组是从大到小排列的, 已经没有顺序对, 即,已经是字典序末尾
            reverse(nums.begin(), nums.end());
        }
        else // nums[i] < nums[i+1]
        {
            // 回头, TODO 二分查找, 刚好比 nums[i] 大一点的nums[j]
            int j = nums.size() - 1;
            for (; nums[j] <= nums[i]; j--)
            {
            }
            // 交换 nums[i] nums[j]
            int tmp = nums[j];
            nums[j] = nums[i];
            nums[i] = tmp;
            // nums[i+1: n-1] 直接逆序交换
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};