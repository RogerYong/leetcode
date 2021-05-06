#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() < 2)
        {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans; // 保存结果
        ans.push_back(intervals[0]);
        int ans_idx = 0;
        for (int i = 1; i < intervals.size(); i++)
        {
            if (ans[ans_idx][1] >= intervals[i][0])
            {
                // 有交集
                vector<int> tmp = {ans[ans_idx][0], max(ans[ans_idx][1], intervals[i][1])};
                ans.pop_back();
                ans.push_back(tmp);
            }
            else
            {
                // 没有交集
                ans.push_back(intervals[i]);
                ans_idx++;
            }
        }
        return ans;
    }
};