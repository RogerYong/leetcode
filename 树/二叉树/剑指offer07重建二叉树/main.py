'''
https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/

https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

给定前序遍历/中序遍历, 恢复二叉树

算法: 递归


之前面试遇到过另一道题: 树的序列化/反序列化, 也可以用这个思路来做

https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree

'''
from typing import List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder or not inorder:
            return None

        if len(preorder) == 1:
            return TreeNode(preorder[0])

        root_val = preorder[0]
        root_idx_inorder = inorder.index(root_val)

        left_tree_inorder = inorder[:root_idx_inorder]
        right_tree_inorder = inorder[root_idx_inorder + 1:]

        len_left_tree = len(left_tree_inorder)
        left_tree_preorder = preorder[1:1 + len_left_tree]
        right_tree_preorder = preorder[1 + len_left_tree:]

        tree = TreeNode(root_val)
        tree.left = self.buildTree(left_tree_preorder, left_tree_inorder)
        tree.right = self.buildTree(right_tree_preorder, right_tree_inorder)

        return tree
