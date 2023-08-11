import java.util.*;


public class Solution {

    // 改进方法: 自底向上
    // 两个条件
    // 1.左右两个子树的高度差的绝对值不超过1
    // 2. 左右两个子树都是一棵平衡二叉树
    // 在一个函数中就判断了子树是否平衡二叉树以及获取子树的高度. 当函数返回-1, 表示子树不是平衡二叉树; 当函数返回值>=0,表示子树是平衡二叉树, 返回值为子树高度
    // 空树设为0, 叶子节点高度设为1

    // 时间复杂度O(N)
    // 空间复杂度O(N) // 递归栈
    public int getDepth(TreeNode pRoot) {
        if (pRoot == null) {
            // 空树是平衡二叉树, 高度为0
            return 0;
        }

        int leftDepth = getDepth(pRoot.left);
        if (leftDepth == -1) {
            return -1;
        }

        int rightDepth = getDepth(pRoot.right);
        if (rightDepth == -1 || Math.abs(leftDepth - rightDepth) > 1) {
            return -1;
        }

        return Math.max(leftDepth, rightDepth) + 1;
    }

    public boolean IsBalanced_Solution (TreeNode pRoot) {
        return getDepth(pRoot) != -1;
    }
}