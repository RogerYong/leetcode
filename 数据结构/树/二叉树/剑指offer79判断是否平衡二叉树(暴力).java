import java.util.*;


public class Solution {

    // 暴力解法: 自顶向下
    // 重复计算了子树的高度
    // 时间复杂度O(N2)
    // 空间复杂度O(N), 递归栈最大深度N(当二叉树是)
    public int getDepth(TreeNode pRoot){
        if(pRoot==null){
            return 0;
        }
        return Math.max(getDepth(pRoot.left), getDepth(pRoot.right)) + 1;
    }

    public boolean IsBalanced_Solution (TreeNode pRoot) {
        if(pRoot==null){
            return true; // 空树是平衡二叉树
        }

        // 两个条件
        // 1.左右两个子树的高度差的绝对值不超过1
        // 2. 左右两个子树都是一棵平衡二叉树

        int leftDepth = getDepth(pRoot.left);
        int rightDepth = getDepth(pRoot.right);
        // 验证条件1
        if(Math.abs(leftDepth-rightDepth)>1){
            return false;
        }else{
            // 验证条件2
            return IsBalanced_Solution(pRoot.left) && IsBalanced_Solution(pRoot.right);
        }

    }
}