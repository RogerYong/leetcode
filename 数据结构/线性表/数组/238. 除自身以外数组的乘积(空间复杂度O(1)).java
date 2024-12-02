class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] answer = new int[nums.length];
        int[] leftProduct = new int[nums.length];
        int[] rightProduct = new int[nums.length];

        leftProduct[0] = nums[0];
        for(int i=1;i<nums.length-1;i++){
            leftProduct[i] = leftProduct[i-1] * nums[i];
        }

        rightProduct[nums.length-1] = nums[nums.length-1];
        for(int i=nums.length-2;i>0;i--){
            rightProduct[i] = rightProduct[i+1] * nums[i];
        }

        answer[0] = rightProduct[1];
        answer[nums.length-1] = leftProduct[nums.length-2];
        for(int i=1;i<nums.length-1;i++){
            answer[i] = leftProduct[i-1] * rightProduct[i+1];
        }
        return answer;
    }
}