class Solution {
    public void rotate(int[] nums, int k) {
        int realK = k % nums.length;
        if(realK ==0){
            return;
        }
        int[] copy = new int[realK];

        for(int i=0;i<realK;i++){
            copy[i] = nums[nums.length - realK +i];
        }

        for(int i=nums.length-1;i>=realK;i--){
            nums[i] = nums[i-realK];
        }
        for(int i=0;i<realK;i++){
            nums[i] = copy[i];
        }
    }
}