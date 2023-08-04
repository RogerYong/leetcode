import java.util.*;

/**
 * 暴力法
 * 最佳时间复杂度 O(N)
 * 最坏时间复杂度 O(N*N) 超时
 * 
 * 如何优化?
 * 
 * 借助归并排序的分治思想, 分别统计左右两个区间的逆序对, 再归并
 */
public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型一维数组 
     * @return int整型
     */
    public int InversePairs (int[] nums) {
        // write code here

        int cnt = 0;

        int mod = 1000000007;

        for(int i=0;i<nums.length;++i){
            for(int j=i+1; j<nums.length; ++j){
                if(nums[i]>nums[j]){
                    cnt = (cnt + 1) % mod;
                }
            }
        }

        return cnt;
    }
}