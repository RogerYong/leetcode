#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int ans = 1e9;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            // 避免重复枚举
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            int right = nums.size() - 1;
            for (int left = i + 1; left < right;)
            {
                // 避免重复枚举
                if (left > i + 1 and nums[left] == nums[left - 1])
                {
                    left++;
                    continue;
                }
                int tempSum = nums[i] + nums[left] + nums[right];
                if (tempSum == target)
                {
                    return target;
                }
                if (abs(tempSum - target) < abs(ans - target))
                {
                    ans = tempSum;
                }

                if (tempSum > target)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 1, 1, 1};
    int target = 4;
    Solution s;
    cout << s.threeSumClosest(nums, target);
}