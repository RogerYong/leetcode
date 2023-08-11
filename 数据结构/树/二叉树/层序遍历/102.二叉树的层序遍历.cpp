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
        vector<TreeNode *> parent_level;
        parent_level.push_back(root);

        vector<TreeNode *> child_level;
        
        while (!parent_level.empty())
        {
            vector<int> int_level;
            child_level.clear();
            for (auto it = parent_level.begin(); it != parent_level.end(); ++it)
            {
                int_level.push_back((*it)->val);

                if ((*it)->left != nullptr)
                {
                    child_level.push_back((*it)->left);
                }

                if ((*it)->right != nullptr)
                {
                    child_level.push_back((*it)->right);
                }
            }
            vvi.push_back(int_level);

            parent_level = child_level;
        }

        return vvi;
    }
};