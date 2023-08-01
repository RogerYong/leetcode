/**
 * 
 * 求最小的k个数用大根堆
 * 
 * 求最大的k个数用小根堆
 * 
 * 
 */

 import java.util.*;


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

        if (input == null || input.length == 0 || k==0) {
            return ans;
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>((a, b)-> b - a); // 大顶堆
        for (int i : input) {
            // 每次循环的复杂度是O(logk)
            if (pq.size() < k) {
                pq.offer(i);
            } else {
                if ( pq.peek() > i) {
                    pq.poll();
                    pq.offer(i);
                }
            }
        }

        ans.addAll(pq);
        // 

        return ans;
    }
}