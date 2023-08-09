/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> res;

        TreeNode*predecessor =nullptr; // 当前节点的前驱节点


        while (root != nullptr){
            if(root->left!=nullptr){
                predecessor = root->left;

                while(predecessor->right!=nullptr && predecessor->right!=root){
                    predecessor = predecessor->right;
                }
                if(predecessor->right==nullptr){
                    // 当前节点的左子树没遍历过
                    // 找到了root的前驱节点
                    predecessor->right = root;
                    root = root->left;
                }else{
                    // 当前节点的左子树已经被遍历过
                    predecessor->right = nullptr; // 恢复
                     res.push_back(root->val);
                    root = root->right;
                }
            }else{
                res.push_back(root->val);
                root = root->right;
            }


        }
        return res;
    }
};