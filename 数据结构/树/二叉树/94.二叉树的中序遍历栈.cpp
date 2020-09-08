#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *root)
{
    stack<TreeNode *> S;
    vector<int> v;
    TreeNode *rt = root;
    while (rt || S.size())
    {
        while (rt)
        {
            S.push(rt);
            rt = rt->left;
        }
        rt = S.top();
        S.pop();
        v.push_back(rt->val);
        rt = rt->right;
    }
    return v;
}
