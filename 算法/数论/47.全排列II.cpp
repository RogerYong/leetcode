#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> vis;
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        ans = vector<vector<int>>();
        path = vector<int>();
        vis = vector<int>(nums.size(), 0);

        dfs(nums);

        return ans;
    }
    void dfs(vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            ans.push_back(path);

            return;
        }

        for (int i = 0; i < nums.size();)
        {
            if (vis[i] == 0)
            { // 没访问过
                vis[i] = 1;
                path.push_back(nums[i]);
                dfs(nums);
                path.pop_back();
                vis[i] = 0;

                int next_i = i + 1;
                while (next_i < nums.size() && (nums[next_i] == nums[i]))
                {
                    next_i++;
                }
                i = next_i;
            }
            else
            {
                i++;
            }
        }
    }
};
int main()
{
    vector<int> nums({1, 1, 2});
    Solution s;
    auto ans = s.permuteUnique(nums);
    return 0;
}