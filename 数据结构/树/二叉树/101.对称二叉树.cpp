// 先序遍历/递归

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
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        return isSym(root->left, root->right);
    }

    bool isSym(TreeNode *a, TreeNode *b)
    {
        if (a == nullptr && b == nullptr)
        {
            return true;
        }
        else if (a == nullptr || b == nullptr)
        {
            return false;
        }
        else
        {
            return (a->val == b->val) && isSym(a->left, b->right) && isSym(a->right, b->left);
        }
    }
};