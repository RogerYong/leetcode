import java.util.*;
/**
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {

    int depth = 0;


public void dfs(TreeNode root, int d){
    if(root ==null){
        return;
    }
    int curD = d+1;
    depth = Math.max(curD, depth);
    dfs(root.left, curD);
    dfs(root.right, curD);
}

    public int TreeDepth(TreeNode root) {
        dfs(root, 0);
        return depth;
    }
}
