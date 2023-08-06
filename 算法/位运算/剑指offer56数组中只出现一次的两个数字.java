import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型一维数组
     * @return int整型一维数组
     */
    public int[] FindNumsAppearOnce (int[] nums) {
        // write code here
        if (nums == null  | nums.length == 0) {
            return null;
        }
        int tmp = 0;
        for (int i : nums) {
            tmp = tmp ^ i;
        }


        int mask = 1;
        while ((mask & tmp) == 0) {
            mask = mask << 1;
        }


        int a = 0;
        int b = 0;
        for (int i : nums) {
            if ((mask & i) == 0) {
                a ^= i;
            } else {
                b ^= i;
            }
        }


        if (a > b) {
            int c = a;
            a = b ;
            b = c;
        }



        return new int[] {a, b};
    }
}