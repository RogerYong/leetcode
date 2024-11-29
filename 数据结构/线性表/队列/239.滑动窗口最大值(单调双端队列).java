import java.util.LinkedList;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        // 考虑到两个性质: 
        // 1. 滑动窗口. 队列中元素下标不在滑动创建内
        // 2. 当前窗口最大. 
        // 
        // 直接使用单调队列: 从队首到队尾, 下标越来越大, 大小越来越小
        // 怎么维护单调队列?
        // 每次滑动窗口, 
        // (1) 从队首往后遍历, 如果队首元素下标不在滑动窗口内, 则队首移除移除直到队列为空 或 队首元素在滑窗内
        // (2) 如果当前元素>=队尾元素, 则把队尾元素移除, 重复, 直到队列为空 或 队尾元素> 当前元素, 把当前元素插入队尾
        // (3) 堆首元素为当前滑窗最大值

        // 总结: 时间复杂度O(N), 空间复杂度O(k)

        if(nums.length-k+1 <=0){
            return null;
        }
        int[] ans = new int[nums.length-k+1];
        LinkedList<Integer> ll = new LinkedList<>(); // 存放的是下标
        for(int i=0;i<nums.length;i++){
            // 移除队首元素
            while (!ll.isEmpty() && ll.getFirst()<=i-k) {
                ll.removeFirst();
            }
            // 插入元素
            while(!ll.isEmpty() && nums[ll.getLast()]<=nums[i]){
                ll.removeLast();
            }
            ll.addLast(i);
            if(i>=k-1){
                // 获取队首元素
                ans[i-k+1] = nums[ll.getFirst()];
            }
   
        }
        return ans;
    }
}