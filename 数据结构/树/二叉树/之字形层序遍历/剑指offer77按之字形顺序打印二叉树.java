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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pRoot TreeNode类
     * @return int整型ArrayList<ArrayList<>>
     */
    public ArrayList<ArrayList<Integer>> Print (TreeNode pRoot) {
        // write code here
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

        if (pRoot == null) {
            return ans;
        }


        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(pRoot);
        boolean leftToRight = true;

        while (!queue.isEmpty()) {
            int curSize = queue.size();

            ArrayList<Integer> curAns = new ArrayList<>();


            for (int i = 0; i < curSize; ++i) {

                TreeNode curNode = queue.poll();

                curAns.add(curNode.val);

                if (curNode.left != null) {
                    queue.offer(curNode.left);
                }
                if (curNode.right != null) {
                    queue.offer(curNode.right);
                }
            }

            if (!leftToRight) {
                Collections.reverse(curAns);
            }
            ans.add(curAns);
            leftToRight = !leftToRight;
        }
        return ans;
    }
}