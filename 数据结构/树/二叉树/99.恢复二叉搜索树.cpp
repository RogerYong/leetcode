// 二叉搜索树/二叉查找树
// 左子树 < root < 右子树
// 性质: 中序遍历 是 有序的
// 方法: 通过中序遍历

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        // 中序遍历, 空间复杂度O(n), 时间复杂度O(n)
        vector<TreeNode *> inorder = inorderTraversal(root);

        // 寻找idx, inorder[idx] > inorder[idx+1]. 空间复杂度O(1), 时间复杂度O(n)
        vector<int> indices;

        for (int i = 0; i < inorder.size() - 1; i++)
        {
            if (inorder[i]->val > inorder[i + 1]->val)
            {
                indices.push_back(i);
            }
        }

        // 交换
        int i, j;
        if (indices.size() == 1)
        {
            i = indices[0];
            j = i + 1;
        }
        else if (indices.size() == 2)
        {
            i = indices[0];
            j = indices[1] + 1;
        }
        std::swap(inorder[i]->val, inorder[j]->val);
    }

    // 非递归的中序遍历, 利用栈
    vector<TreeNode *> inorderTraversal(TreeNode *root)
    {
        vector<TreeNode *> inorder;
        stack<TreeNode *> s;
        TreeNode *temp = root;
        while (temp || !s.empty())
        {
            while (temp)
            {
                s.push(temp);
                temp = temp->left;
            }

            temp = s.top(); // 被弹出来的temp: temp->left已经遍历完毕
            s.pop();

            inorder.push_back(temp); // 遍历temp本身
            temp = temp->right;      // 遍历temp->right
        }
        return inorder;
    }
};
