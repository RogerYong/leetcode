import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param sum int整型
     * @return int整型ArrayList<ArrayList<>>
     */
    public ArrayList<ArrayList<Integer>> FindContinuousSequence (int sum) {
        // write code here


        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        for (int l = 1, r = 2; l < r;) {
            int s = (l + r) * (r - l + 1) / 2;
            if (s == sum) {
                ArrayList<Integer> ai = new ArrayList<>();
                for (int k = l; k <= r; ++k) {
                    ai.add(k);
                }
                ans.add(ai);
                l++; // 别忘了窗口移动
            } else if (s < sum) {
                r++;
            } else {
                l++;
            }
        }
        return ans;
    }
}