import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param num int整型一维数组
     * @param size int整型
     * @return int整型ArrayList
     */


    public ArrayList<Integer> maxInWindows (int[] num, int size) {
        // write code here
        ArrayList<Integer>  ans = new ArrayList<>();
        if (num == null || size==0 || num.length < size ) {
            return ans;
        }

        int maxVal = -10001;
        int maxIdx = -1;

        for (int left = 0;  left + size - 1 < num.length; ++left) {
            if (maxIdx < left) {
                maxIdx = left;
                maxVal = num[left];
            }
            for (int j = maxIdx + 1; j <= left + size - 1; ++j ) {
                if (num[j] >= maxVal) {
                    maxVal = num[j];
                    maxIdx = j;
                }
            }
            ans.add(maxVal);
        }
        return ans;
    }
}