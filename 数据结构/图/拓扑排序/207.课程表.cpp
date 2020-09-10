#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adjacent_table(numCourses);
        vector<int> indegree(numCourses, 0); // 记录每个点的入度
        vector<int> topsort_result;          // 拓扑排序的结果

        for (auto it = prerequisites.begin(); it != prerequisites.end(); ++it)
        {
            int src, target;
            src = (*it)[1];
            target = (*it)[0];
            adjacent_table[src].push_back(target);
            indegree[target]++;
        }
        return top_sort(adjacent_table, indegree, topsort_result);
    }

    bool top_sort(vector<vector<int>> &adjacent_table, vector<int> &indegree, vector<int> &topsort_result)
    {
        topsort_result.clear();

        queue<int> q;

        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            topsort_result.push_back(v);

            auto neibors = adjacent_table[v];
            for (auto it = neibors.begin(); it != neibors.end(); ++it)
            {
                int a_neighbor = *it;
                indegree[a_neighbor]--;
                if (indegree[a_neighbor] == 0)
                {
                    q.push(a_neighbor);
                }
            }
        }
        if (topsort_result.size() == adjacent_table.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    int numCourses = 2;
    vector<vector<int>> prerequisites;
    prerequisites.push_back(vector<int>{1, 0});
    prerequisites.push_back(vector<int>{0, 1});
    Solution s;
    cout << s.canFinish(numCourses, prerequisites);
}