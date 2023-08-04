import java.util.*;


// 时间复杂度 O(n*log2n) 每次堆的插入log2n, 每次hash  contains O(1)
// 空间复杂度 O(n)
// TODO 有重复计算, 所以用 hash. 可通过动态规划, 去掉重复计算



public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param index int整型
     * @return int整型
     */
    public int GetUglyNumber_Solution (int index) {
        // write code here
        if (index == 0) {
            return 0;
        }

        List<Long> nums = new ArrayList<>();
        nums.add(1L);

        PriorityQueue<Long> pq = new PriorityQueue<>(); // 小顶堆
        pq.offer(2L);
        pq.offer(3L);
        pq.offer(5L);

        Set<Long> vis = new HashSet<>();
        vis.add(1L);
        vis.add(2L);
        vis.add(3L);
        vis.add(5L);

        while (nums.size() < index) {
            Long nextNum = pq.poll();
            nums.add(nextNum);

            Long nextNum2 = nextNum * 2;
            Long nextNum3 = nextNum * 3;   
            Long nextNum5 = nextNum * 5;

 
            if (! vis.contains(nextNum2)) {
                pq.offer(nextNum2);
                vis.add(nextNum2);
            }
            if (! pq.contains(nextNum3)) {
                pq.offer(nextNum3);
                vis.add(nextNum3);
            }
            if (! pq.contains(nextNum5)) {
                pq.offer(nextNum5);
                vis.add(nextNum5);
            }
            // for (int i : nums) {
            //     System.out.println(i);
            // }
        }
        return nums.get(index - 1).intValue();
    }
}