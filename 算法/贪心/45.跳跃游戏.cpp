#include <bits/stdc++.h>
using namespace std;

// 也可以称为广搜
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int left = 0, right = 0;
        int step = 0;

        for (int i = 0; i < nums.size()-1; i++)
        {

            right = max(right, i + nums[i]);
            if (i == left)
            {
                left = right;
                step++;
            }
        }
        return step;
    }
};