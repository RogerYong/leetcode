import java.util.*;

/*
 * public class TreeNode {
 *   int val = 0;
 *   TreeNode left = null;
 *   TreeNode right = null;
 *   public TreeNode(int val) {
 *     this.val = val;
 *   }
 * }
 */

public class Solution {

    public int lowestCommonAncestor (TreeNode root, int p, int q) {
        // write code here
        if (root == null) {
            return -1;
        }

        if (root.val == p) {
            return p;
        }
        if (root.val == q) {
            return q;
        }

        int min = Math.min(p, q);
        int max = Math.max(p, q);

        if (min > root.val) {
            return lowestCommonAncestor(root.right, min, max);
        }

        if (max < root.val) {
            return lowestCommonAncestor(root.left, min, max);
        }

        return root.val;
    }
}