import java.util.*;

// DFS的递归实现

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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @param target int整型
     * @return int整型ArrayList<ArrayList<>>
     */
    public ArrayList<ArrayList<Integer>> FindPath (TreeNode root, int target) {
        // write code here
        ArrayList<ArrayList<Integer>> aai = new ArrayList<>();
        if (root == null) {
            return aai;
        }

        if (root.left != null) {
            // 当前节点不是叶子节点
            ArrayList<ArrayList<Integer>> caai = FindPath(root.left, target - root.val);

            for (ArrayList<Integer> lai : caai) {
                ArrayList<Integer> ai = new ArrayList<>();
                ai.add(root.val);
                ai.addAll(lai);
                aai.add(ai);
            }
        }

        if (root.right != null) {
            // 当前节点不是叶子节点
            ArrayList<ArrayList<Integer>> caai = FindPath(root.right, target - root.val);
            for (ArrayList<Integer> lai : caai) {
                ArrayList<Integer> ai = new ArrayList<>();
                ai.add(root.val);
                ai.addAll(lai);
                aai.add(ai);
            }
        }

        if (root.left == null && root.right == null && root.val == target) {
            // 当前节点是叶子节点 且 是指定路径
            ArrayList<Integer> ai = new ArrayList<>();
            ai.add(target);
            aai.add(ai);
        }
        return aai;

    }
}