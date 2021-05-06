#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        // 排序
        sort(candidates.begin(), candidates.end());

        // 初始化
        ans = vector<vector<int>>();
        path = vector<int>();

        // 深搜
        dfs(candidates, target, 0); // 搜索
        return ans;
    }
    void dfs(vector<int> &candidates, int target, int idx)
    {
        if (target == 0) // 结束
        {
            ans.push_back(path);
            return;
        }
        // idx: 之前搜过的就不搜了
        for (int i = idx; i < candidates.size();)
        {
            // 跳过已经搜索过的, 避免重复
            if (candidates[i] > target)
            {
                return;
            }
            else // candidates[i] <= target
            {
                path.push_back(candidates[i]);
                dfs(candidates, target - candidates[i], i + 1);
                path.pop_back();

                // i处的已经搜索过了, 需要跳过
                int next_idx = i + 1;
                while (next_idx < candidates.size() && candidates[next_idx] == candidates[i])
                {
                    next_idx++;
                }
                i = next_idx;
            }
        }
    }
};