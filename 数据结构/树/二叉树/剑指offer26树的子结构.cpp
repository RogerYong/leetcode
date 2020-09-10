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
    void findNode(TreeNode *A, TreeNode *node, vector<TreeNode *> &v)
    {
        // 深度优先搜索
        if (A == nullptr || node == nullptr)
        {
            return;
        }

        if (A->val == node->val)
        {
            v.push_back(A);
        }
        findNode(A->left, node, v);
        findNode(A->right, node, v);
    }

    bool compare_node(TreeNode *A, TreeNode *B)
    {
        if (B == nullptr) // 非root节点中, 当B是nullptr, 那也算子结构
        {
            return true;
        }

        if (A == nullptr)
        {
            return false;
        }

        // A B 不为空
        if (A->val == B->val && compare_node(A->left, B->left) && compare_node(A->right, B->right))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (A == nullptr || B == nullptr)
        {
            return false;
        }

        // 确保两个根节点不为空

        // 1. A中找到B的根节点
        vector<TreeNode *> B_in_A;
        findNode(A, B, B_in_A);

        // 2. 比较树
        for (auto it = B_in_A.begin(); it != B_in_A.end(); ++it)
        {
            if (compare_node(*it, B))
            {
                return true;
            }
        }
        return false;
    }
};