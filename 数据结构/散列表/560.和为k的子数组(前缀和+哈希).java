class Solution {
    public int subarraySum(int[] nums, int k) {
        int len = nums.length;

        int[] sums = new int[len+1];
        sums[0] = 0;
        for(int i=0;i<len;++i){
            sums[i+1] = nums[i] + sums[i];
        }
        // SUM[0,i]: 表示从下标0, 到下标为i的的和, i>=0, 用数组sum[i+1]表示, 即SUM[0,i] = sum[i+1]
        // SUBSUM[i,j]: 表示从下标i到下标j的和,其中,0<=i<j, SUBSUM[i,j] = SUM[0,j] - SUM[0,i-1]  = sum[j+1] - sum[i]
        // 
        // 可以用哈希法, 把sum[j+1] - k = sum[i] 的个数存起来

        Map<Integer,Integer> sumCnt = new HashMap<>();
        sumCnt.put(0, 1);
        int ans = 0;
        for(int j=0;j<len;j++){
            int sumJ = sums[j+1];

            int sumI = sumJ - k; // sum[i]
            int numI = sumCnt.getOrDefault(sumI, 0);
            ans = ans + numI;

            sumCnt.put(sumJ,  sumCnt.getOrDefault(sumJ,0) + 1);
        }
        return ans;
    }
}