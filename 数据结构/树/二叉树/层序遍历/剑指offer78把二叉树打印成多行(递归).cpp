/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pRoot TreeNode类
     * @return int整型vector<vector<>>
     */

    void recursivePrint(TreeNode* pRoot, int curLevel, vector<vector<int>>& vvi){
        if(pRoot==nullptr){
            return;
        }
        if(vvi.size()<=curLevel){
            vector<int> vi;
            vvi.push_back(vi);
        }
        vvi[curLevel].push_back(pRoot->val);
        recursivePrint(pRoot->left, curLevel+1, vvi);
        recursivePrint(pRoot->right, curLevel+1, vvi);
    }

    vector<vector<int> > Print(TreeNode* pRoot)     {
        vector<vector<int>> vvi;
        if (pRoot == nullptr) {
            return vvi;
        }
        recursivePrint(pRoot, 0, vvi);
        return vvi;
    }
};