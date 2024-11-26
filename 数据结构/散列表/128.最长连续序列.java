class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums == null){
            return 0;
        }
        Set<Integer> numSet = new HashSet<>();
        for(int num : nums){
            numSet.add(num);
        }
        int longestConsecutive = 0;
        for(Integer num : numSet){
            if(numSet.contains(num - 1)){
                continue;
            }
            Integer currentNum = num;
            Integer consecutive = 1;
            while(numSet.contains(currentNum+1)){
                currentNum += 1;
                consecutive += 1;
            }
            longestConsecutive = Math.max(longestConsecutive, consecutive);
        }
        return longestConsecutive;
    }
}