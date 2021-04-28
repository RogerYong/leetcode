// 二叉搜索树/二叉查找树
// 左子树 < root < 右子树
// 性质: 中序遍历 是 有序的
// 方法: 通过中序遍历
// 优化思路: 在中序遍历过程中, 找到不满足顺序的节点(用pair表示), 可以减少内存使用
// 当找到两个pair时, 可以退出中序遍历

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
        // 中序遍历, 空间复杂度O(h), 时间复杂度O(n), h是树的高度, O(h)是栈内存
        vector<pair<TreeNode *, TreeNode *>> pairs = inorderTraversal(root);

        // 交换
        TreeNode *i, *j;
        if (pairs.size() == 1)
        {
            i = pairs[0].first;
            j = pairs[0].second;
        }
        else if (pairs.size() == 2)
        {
            i = pairs[0].first;
            j = pairs[1].second;
        }
        std::swap(i->val, j->val);
    }

    // 非递归的中序遍历, 利用栈
    vector<pair<TreeNode *, TreeNode *>> inorderTraversal(TreeNode *root)
    {
        TreeNode *previous = nullptr; // 前一个节点

        vector<pair<TreeNode *, TreeNode *>> pairs; // 顺序错误的对
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

            if (previous != nullptr && previous->val > temp->val)
            {
                pairs.push_back(make_pair(previous, temp));
                if (pairs.size() >= 2)
                {
                    break;
                }
            }
            previous = temp;
            temp = temp->right; // 遍历temp->right
        }
        return pairs;
    }
};
