#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (nums.size() == 0 || target < nums.front() || target > nums.back())
        {
            return {-1, -1};
        }
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;

        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                break;
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

        if (nums[mid] == target)
        {
            vector<int> ans;
            int left_left = left;
            int left_right = mid;

            int right_left = mid;
            int right_right = right;

            while (left_left <= left_right)
            {
                mid = left_left + (left_right - left_left) / 2;

                if (nums[mid] == target)
                {
                    if (mid == 0 || nums[mid - 1] < target)
                    {
                        ans.push_back(mid);
                        break;
                    }
                    else // nums[mid - 1] == target
                    {
                        left_right = mid - 1;
                    }
                }
                else // nums[mid] < target
                {
                    left_left = mid + 1;
                }
            }

            while (right_left <= right_right)
            {
                mid = right_left + (right_right - right_left) / 2;

                if (nums[mid] == target)
                {
                    if (mid == nums.size() - 1 || nums[mid + 1] > target)
                    {
                        ans.push_back(mid);
                        break;
                    }
                    else // nums[mid + 1] == target
                    {
                        right_left = mid + 1;
                    }
                }
                else // nums[mid] > target
                {
                    right_right = mid - 1;
                }
            }
            return ans;
        }
        else
        {
            return {-1, -1};
        }
    }
};