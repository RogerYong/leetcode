// 暴力法: O(n3)
// 缺点: 1.需要去重, 2.遍历,大量无效组合,时间复杂度高

// 通过排序的方式, 避免重复枚举
// 其二, (a,b,c) 三个数, 当a>0时,表示, 后续无满足条件的元组,可以提前停止无效枚举

// 由于约束的存在, 实际的复杂度O(n2)
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        // 从小到大排序
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() && nums[i] <= 0; i++)
        {
            // 避免重复枚举
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int right = nums.size() - 1;
            for (int left = i + 1; left < right; left++)
            {
                // 避免重复枚举
                if (left > i + 1 and nums[left] == nums[left - 1])
                {
                    continue;
                }

                // 枚举第3个数
                while (left < right and nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }

                if (left == right)
                {
                    break;
                }
                if (nums[i] + nums[left] + nums[right] == 0)
                {
                    res.push_back({nums[i], nums[left], nums[right]});
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v({-1, 0, 1, 2, -1, -4});
    auto res = s.threeSum(v);
    for (auto r : res)
    {
        cout << r[0] << r[1] << r[2] << endl;
    }
    cout << "done" << endl;
    return 0;
}