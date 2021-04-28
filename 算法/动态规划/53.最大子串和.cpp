#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        vector<int> dp;
        dp.assign(nums.cbegin(), nums.cend());

        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            maxSum = max(dp[i], maxSum);
        }
        return maxSum;
    }
};