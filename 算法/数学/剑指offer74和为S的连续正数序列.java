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


        for (int i = 1; i * 2 < sum ; ++i) {
            double j = (Math.sqrt(1 + 8 * sum + 4 * i * i - 4 * i) - 1) / 2;
            int right = (int) j;
            if (right > i &&  j==right ) {
                // 知识点: 在int数据范围内, 使用 double 先转int再转double, 可判断double是否整数
                ArrayList<Integer> ai = new ArrayList<>();
                for (int k = i; k <= right; ++k) {
                    ai.add(k);
                }
                ans.add(ai);
            }
        }
        return ans;
    }
}