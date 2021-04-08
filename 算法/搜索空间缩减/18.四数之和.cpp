// 在三数之和的基础上加一个外层循环
// O(n3)

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        // 四个指针 i,j, left, right
        for (int i = 0; i < nums.size(); i++)
        {
            // 避免重复枚举
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            for (int j = i + 1; j < nums.size(); j++)
            {
                // 避免重复枚举
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }

                int right = nums.size() - 1;
                for (int left = j + 1; left < right; left++)
                {
                    // 避免重复枚举
                    if (left > j + 1 and nums[left] == nums[left - 1])
                    {
                        continue;
                    }

                    // 枚举第4个数
                    while (left < right and nums[i] + nums[j] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                    if (left == right)
                    {
                        break;
                    }
                    if (nums[i] + nums[j] + nums[left] + nums[right] == target)
                    {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    }
                }
            }
        }
        return res;
    }
};