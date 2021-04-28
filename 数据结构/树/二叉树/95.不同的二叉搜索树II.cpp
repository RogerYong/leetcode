// 递归
#include <vector>
#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<vector<TreeNode *>>> table;
    vector<TreeNode *> generateTrees(int n)
    {
        // 打表法, 空间换时间
        // table[i][j] 表示 [i,j]生成的树的集合
        table.assign(n + 2, vector<vector<TreeNode *>>(n + 2));
        if (n == 0)
        {
            return {};
        }
        return getTrees(1, n);
    }

    vector<TreeNode *> getTrees(int b, int e)
    {
        // 带记忆化的
        if (!table[b][e].empty())
        {
            return table[b][e];
        }

        if (b > e)
        {
            return {nullptr}; // 用nullptr代替空的vector
        }

        for (int i = b; i <= e; ++i)
        {
            // 选择i作为根节点
            for (auto &l : getTrees(b, i - 1))
            {
                for (auto &r : getTrees(i + 1, e))
                {
                    TreeNode *temp = new TreeNode(i, l, r);
                    table[b][e].push_back(temp);
                }
            }
        }

        return table[b][e];
    }
};

int main()
{
    auto s = Solution();
    auto r = s.generateTrees(8);
}