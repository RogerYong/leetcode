import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param number int整型
     * @return int整型
     */
    public int jumpFloorII (int number) {
        // write code here
        int[] ans = new int[number + 1];

        ans[0] = 1;
        ans[1] = 1;

        for (int i = 2; i <= number; ++i) {
            // ans[i] = 0;
            // for(int j=0;j<i;++j){
            //     ans[i] += ans[j];
            // }
            ans[i] = ans[i-1] * 2;

        }
        return ans[number];
    }
}