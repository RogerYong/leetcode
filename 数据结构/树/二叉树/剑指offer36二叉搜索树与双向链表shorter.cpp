/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
  public:
    TreeNode* left = nullptr;
    TreeNode* pre = nullptr; 
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == nullptr) {
            return nullptr;
        }
        Convert(pRootOfTree->left);
        if (left == nullptr) {
            left = pRootOfTree;
        }

		if(pre!=nullptr){
			pre->right = pRootOfTree;
			pRootOfTree->left = pre;
		}
		pre = pRootOfTree;
		Convert(pRootOfTree->right);

        return left;
    }


};
