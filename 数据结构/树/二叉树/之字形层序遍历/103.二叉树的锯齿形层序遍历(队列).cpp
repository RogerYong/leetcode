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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> vvi; // 层序遍历结果
        bool left_to_right = true;
        if (root == nullptr)
        {
            return vvi;
        }
        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            int size_current_level = q.size();
            vector<int> int_level; // 当前层的结果, 临时保存

            // 先顺序获取完下一层, 再考虑当前层的遍历顺序

            // 1.获取下一层, 从左往右
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

            // 2.根据flag 对int_level判断是否反转
            if (!left_to_right) // 从右往左
            {
                reverse(int_level.begin(), int_level.end());
            }
            vvi.push_back(int_level);
            left_to_right = !left_to_right;
        }

        return vvi;
    }
};