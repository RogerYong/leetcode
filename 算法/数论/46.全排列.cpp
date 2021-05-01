#include <bits/stdc++.h>
using namespace std;

// 搜索
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> path;

        set<int> available;
        for (auto i : nums)
        {
            available.insert(i);
        }
        dfs(path, available, ans);
        return ans;
    }

    void dfs(vector<int> &path, set<int> &available, vector<vector<int>> &ans)
    {
        if (available.empty())
        {
            ans.push_back(path);
            return;
        }

        for (auto it = available.begin(); it != available.end(); it++)
        {
            set<int> a(available);
            a.erase(*it);
            path.push_back(*it);
            dfs(path, a, ans);
            path.pop_back();
        }
    }
};