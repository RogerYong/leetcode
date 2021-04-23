#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 找到旋转数组最小值的idx
    int minArray(vector<int> &numbers)
    {
        if (!(&numbers) || numbers.size() == 0)
        {
            return -1;
        }
        if (numbers.size() == 1)
        {
            return 0;
        }

        vector<int>::size_type left = 0;
        vector<int>::size_type right = numbers.size() - 1;

        while (left < right)
        {
            auto mid = left + (right - left) / 2;
            if (numbers[mid] < numbers[right])
            {
                right = mid;
            }
            else if (numbers[mid] > numbers[right])
            {
                left = mid + 1;
            }
            else // numbers[mid] == numbers[right]
            {
                right = right - 1;
            }
        }

        return left;
    }

    int binarySearch(vector<int> &nums, int left, int right, int target)
    {
        if (!(&nums) || nums.size() == 0)
        {
            return -1;
        }
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return -1;
    }
    int search(vector<int> &nums, int target)
    {

        // 先找到旋转的位置
        // 然后就知道两个区间的范围
        // 如果在target在范围内则二分
        if (!(&nums) || nums.size() == 0)
        {
            return -1;
        }
        if (nums.size() == 1)
        {
            return nums[0] == target ? 0 : -1;
        }
        int idxMin = minArray(nums); // k范围 [0, nums.size()]

        int left1 = 0;
        int right1 = idxMin - 1;

        int left2 = idxMin;
        int right2 = nums.size() - 1;

        if (right1 >= 0 && target >= nums[left1] && target <= nums[right1])
        {
            // 在范围内二分查找
            return binarySearch(nums, left1, right1, target);
        }
        if (target >= nums[left2] && target <= nums[right2])
        {
            // 在范围内二分查找
            return binarySearch(nums, left2, right2, target);
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> vi = {4, 5, 6, 7, 0, 1, 2};
    int target = 4;
    s.search(vi, target);
}