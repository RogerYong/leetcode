import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @return string字符串ArrayList
     */

    ArrayList<String> ans ;
    List<Boolean> vis ;


    public ArrayList<String> Permutation (String str) {
        if (str == null || str.isEmpty()) {
            return null;
        }
        // write code here
        char[] ca = str.toCharArray();
        Arrays.sort(ca);

        ans = new ArrayList<>();
        vis = new ArrayList<>();
        // System.out.println(vis.size());
        for (int i = 0; i < ca.length; ++i) {
            vis.add(false);
            // System.out.println(vis.get(i));
        }
        
        dfs(ca, "");

        return ans;
    }


    private void dfs(char[] ca, String curPath) {
        if (curPath.length() == ca.length) {
            ans.add(curPath);
            return;
        }

        for (int i = 0; i < ca.length;) {
            if (vis.get(i)) {
                ++i;
            } else {
                vis.set(i, true);
                String newPath = curPath + ca[i];

                dfs(ca, newPath);

                vis.set(i, false);

                // 跳过重复的字符
                int nextI = i + 1;
                while ( nextI < ca.length && ca[i] == ca[nextI] ) {
                    ++nextI;
                }
                i = nextI;
            }
        }
    }
}