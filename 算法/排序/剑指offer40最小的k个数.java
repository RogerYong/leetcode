import java.util.*;

/**
 * 
 * 排序法
 * 
 * 时间复杂度: O(nlogn)
 * 空间复杂度: O(1)
 */
public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param input int整型一维数组 
     * @param k int整型 
     * @return int整型ArrayList
     */
    public ArrayList<Integer> GetLeastNumbers_Solution (int[] input, int k) {
        // write code here
        ArrayList<Integer> ans = new ArrayList<>();

        if(input==null || input.length==0){
            return ans;
        }

        Arrays.sort(input);
        for(int i=0;i<k && i < input.length;i++){
            ans.add(input[i]);
        }
        return ans;
    }
}