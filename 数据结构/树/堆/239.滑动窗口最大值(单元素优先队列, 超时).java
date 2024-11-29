class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        // 考虑到两个性质: 
        // 1. 滑动窗口. 队列中元素下标不在滑动创建内
        // 2. 当前窗口最大. 
        // 
        // 直接使用优先队列, 每循环使用查找某个元素并删除, 时间复杂度n * k, 极端情况下k=n,超时, n^2
        // 考虑优先队列的时间复杂度, k是队列大小, peek:O(1), poll:O(log(k)), add O(log(k-1)), 查找某个元素并删除 O(k)


        PriorityQueue<Integer> pq = new PriorityQueue<>((a,b) -> b-a); // 大顶堆


        if(nums.length-k+1 <=0){
            return null;
        }
        int[] ans = new int[nums.length-k+1];
        for(int i=0;i<k;i++){
            pq.add(nums[i]);
        }
        ans[0] = pq.peek();

        for(int i=k;i<nums.length;i++){
            pq.add(nums[i]);
            pq.remove(nums[i-k]);
            ans[i-k+1] = pq.peek();
        }
        return ans;
    }
}