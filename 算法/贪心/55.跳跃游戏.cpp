#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
        {
            return true;
        }
        int max_idx = nums[0];
        for (int i = 1; i <= max_idx && i < len - 1; i++)
        {
            max_idx = max(max_idx, i + nums[i]);
        }
        return max_idx >= (len - 1);
    }
};