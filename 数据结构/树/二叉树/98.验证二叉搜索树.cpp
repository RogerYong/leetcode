// 中序遍历
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
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
        {
            return false;
        }
        // 中序遍历, 空间复杂度O(n), 时间复杂度O(n)
        vector<TreeNode *> inorder = inorderTraversal(root);

        for (int i = 0; i < inorder.size() - 1; i++)
        {
            if (inorder[i]->val >= inorder[i + 1]->val)
            {
                return false;
            }
        }
        return true;
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