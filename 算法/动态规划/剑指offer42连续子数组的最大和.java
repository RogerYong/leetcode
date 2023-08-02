import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型一维数组 
     * @return int整型
     */
    public int FindGreatestSumOfSubArray (int[] array) {
        // write code here
        if(array==null || array.length==0){
            return 0;
        }

        int dpI;
        int dpIMinusOne = array[0];
        int maxSum = array[0];

        for(int i=1;i<array.length; ++i, dpIMinusOne =dpI){
            dpI = Math.max( dpIMinusOne + array[i],array[i]);
            maxSum = Math.max(maxSum, dpI);
        }

        return maxSum;
    }
}