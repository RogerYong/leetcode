#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums.size();
        }

        //
        for (auto it = nums.begin() + 1; it != nums.end();)
        {
            if (*it == *(it - 1))
            {
                it = nums.erase(it);
            }
            else
            {
                it++;
            }
        }
        return nums.size();
    }
};