
public class Solution {
    String Serialize(TreeNode root) {

        if (root == null) {
            return "";
        }

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        List<String> as = new ArrayList<>();

        while (!q.isEmpty()) {
            TreeNode node = q.peek();
            q.poll();
            if (node != null) {
                as.add(String.valueOf( node.val));
                q.offer(node.left);
                q.offer(node.right);
            } else {
                as.add( "#");
            }
        }
        // System.out.println(String.join(",", as));
        return String.join(",", as);
    }
    TreeNode Deserialize(String str) {
        // System.out.printlhaon(str);
        if (str == null || str.trim().isEmpty()) {
            return null;
        }
        List<String> as =  Arrays.asList(str.split(","));

        TreeNode root = new TreeNode(Integer.valueOf( as.get(0)));
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        TreeNode parent = null;
        int childIdx = 1;
        while (!q.isEmpty()) {
            parent = q.poll();
            if (childIdx < as.size() && !"#".equals( as.get(childIdx))) {

                TreeNode left = new TreeNode(Integer.valueOf(as.get(childIdx)) );
                q.offer(left);
                parent.left = left;
            }
            if (childIdx + 1 < as.size() && !"#".equals( as.get(childIdx + 1))) {
                TreeNode right = new TreeNode(Integer.valueOf(as.get(childIdx + 1)) );
                q.offer(right);
                parent.right = right;
            }
            childIdx +=2;
        }

        return root;
    }
}