#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        vector<int> dp(nums.size(), 1);

        for (vector<int>::size_type i = 0; i < nums.size(); ++i)
        {
            for (vector<int>::size_type j = 0; j < i; ++j)
            {

                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};