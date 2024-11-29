class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        // 考虑到两个性质: 
        // 1. 滑动窗口. 队列中元素下标不在滑动创建内
        // 2. 当前窗口最大. 
        // 
        // 直接使用优先队列, 每循环使用查找某个元素并删除, 时间复杂度n * k, 极端情况下k=n,超时, n^2
        // 考虑优先队列的时间复杂度, k是队列大小, peek:O(1), poll:O(log(k)), add O(log(k-1)), 查找某个元素并删除 O(k)
        // 避免使用查找某个元素并删除, 从而降低复杂度. 
        // 也就是说堆里面可以保存着不在滑动创建内的元素, 但是需要同时保存下标, 从而区分堆顶元素是否合法, 如果不合法则remove


 
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((int[]a,int[]b) -> {
            return a[0]!=b[0]? b[0] - a[0] : b[1] - a[1];
        }); // 大顶堆

        if(nums.length-k+1 <=0){
            return null;
        }
        int[] ans = new int[nums.length-k+1];
        for(int i=0;i<nums.length;i++){
            pq.add(new int[]{nums[i], i});
            if(i>=k-1){
                while(pq.peek()[1] <= i-k){
                    pq.poll();
                }
                ans[i-k+1] = pq.peek()[0];
            }
        }
        return ans;
    }
}