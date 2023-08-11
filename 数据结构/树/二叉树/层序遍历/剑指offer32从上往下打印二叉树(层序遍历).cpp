#include <bits/stdc++.h>
#include <vector>
#include
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> vi ;
        if (root == nullptr) {
            return vi;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* qf =   q.front();
			q.pop();
			
            vi.push_back(qf->val);
            if (qf->left != nullptr) {
                q.push(qf->left);
            }
            if (qf->right != nullptr) {
                q.push(qf->right);
            }
        }
        return vi;
    }
};
