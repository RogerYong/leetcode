// 层序遍历BFS

#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        // vector<vector<int>> vvi;
        int depth = 0;
        if (root == nullptr)
        {
            return 0;
        }
        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            int size_current_level = q.size();

            for (int i = 0; i < size_current_level; ++i)
            {
                TreeNode *tmp = q.front();
                q.pop();

                if (tmp->left != nullptr)
                {
                    q.push(tmp->left);
                }

                if (tmp->right != nullptr)
                {
                    q.push(tmp->right);
                }
            }
            depth++;
        }

        return depth;
    }
};