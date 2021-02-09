/*
二叉树层序遍历

BFS实现
*/
#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        // 递归 空间复杂度O(N)
        if (root == nullptr)
        {
            return nullptr;
        }
        // BFS
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size_cur_level = q.size();
            Node *left_node = nullptr;
            for (int i = 0; i < size_cur_level; ++i)
            {
                // 当前层节点
                Node *tmp = q.front();
                q.pop();

                // 构造next
                if (left_node != nullptr)
                {
                    left_node->next = tmp;
                }
                left_node = tmp;

                // 下层节点
                if (tmp->left != nullptr)
                {
                    q.push(tmp->left);
                }
                if (tmp->right != nullptr)
                {
                    q.push(tmp->right);
                }
            }
        }

        return root;
    }
};