/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

// 该方法空间复杂度O(n), 时间复杂度O(n)
class Solution {
  public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == nullptr) {
            return nullptr;
        }
        TreeNode* left = ConvertLeft(pRootOfTree->left, pRootOfTree);
        TreeNode* right = ConvertRight(pRootOfTree->right, pRootOfTree);
        return left;
    }

    TreeNode* ConvertLeft(TreeNode* pRootOfTree, TreeNode* head) {
        if (pRootOfTree == nullptr) {
            return head;
        }
        TreeNode* left = ConvertLeft(pRootOfTree->left, pRootOfTree);
        TreeNode* right = ConvertRight(pRootOfTree->right, pRootOfTree);
        right->right = head;
        head->left = right;
        return left;
    }

    TreeNode* ConvertRight(TreeNode* pRootOfTree, TreeNode* head) {
        if (pRootOfTree == nullptr) {
            return head;
        }

		TreeNode* left = ConvertLeft(pRootOfTree->left, pRootOfTree);
        TreeNode* right = ConvertRight(pRootOfTree->right, pRootOfTree);
        left->left = head;
        head->right = left;
        return right;
    }
};
