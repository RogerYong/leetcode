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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> vvi;
        if (root == nullptr)
        {
            return vvi;
        }
        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            int size_current_level = q.size();
            vector<int> int_level;

            for (int i = 0; i < size_current_level; ++i)
            {
                TreeNode *tmp = q.front();
                q.pop();

                int_level.push_back(tmp->val);

                if (tmp->left != nullptr)
                {
                    q.push(tmp->left);
                }

                if (tmp->right != nullptr)
                {
                    q.push(tmp->right);
                }
            }
            vvi.push_back(int_level);
        }

        return vvi;
    }
};