import java.util.*;


// 时间复杂度 O(n*n) 每次堆的contains O(n), 
// 空间复杂度 O(n)
// TODO 不要使用堆的contains, 使用哈希表, 把contains的O(n)变成O(1)


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

        while (nums.size() < index) {
            Long nextNum = pq.poll();
            nums.add(nextNum);
            if (! pq.contains(nextNum * 2)) {
                pq.offer(nextNum * 2);
            }
            if (! pq.contains(nextNum * 3)) {
                pq.offer(nextNum * 3);
            }
            if (! pq.contains(nextNum * 5)) {
                pq.offer(nextNum * 5);
            }
            // for (int i : nums) {
            //     System.out.println(i);
            // }
        }
        return nums.get(index - 1).intValue();
    }
}