#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        if (nums.size() == 0 || target < nums.front())
        {
            return 0;
        }
        else if (target > nums.back())
        {
            return nums.size();
        }
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;

        while (left <= right)
        {
            mid = left + (right - left) / 2;
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
        // right left
        return left;
    }
};