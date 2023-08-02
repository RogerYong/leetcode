import java.util.*;
/**
 * insert 时间复杂度O(logn)
 * GetMedian O(1)
 */

public class Solution {
   PriorityQueue<Integer> rightQueue = new PriorityQueue<>(); // 小顶堆, 保存>=中位数的部分
    PriorityQueue<Integer> leftQueue = new PriorityQueue<>((a,b)->b -a); // 大顶堆, 保存<=中位数的部分
    public void Insert(Integer num) {
       leftQueue.offer(num);
       rightQueue.offer(leftQueue.poll());

       // 平衡两个堆
       // 偶数个数情况下, 两个堆的大小一致
       // 奇数个数情况下, leftQueue.size() = rightQUeue.size() + 1
       if(rightQueue.size()> leftQueue.size()){
        leftQueue.offer(rightQueue.poll());
       } 
    }

    public Double GetMedian() {
        if(leftQueue.size()==rightQueue.size()){
            return (leftQueue.peek() + rightQueue.peek()) * 0.5;
        }else{
            return Double.valueOf(leftQueue.peek());
        }
    }
}
