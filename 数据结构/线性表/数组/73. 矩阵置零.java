class Solution {
    public void setZeroes(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        Set<Integer> zeroRowIdx = new HashSet<>();
        Set<Integer> zeroColumnIdx = new HashSet<>();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    zeroRowIdx.add(i);
                    zeroColumnIdx.add(j);
                }
            }
        }

        for(int i: zeroRowIdx){
            for(int j=0;j<n;j++){
                matrix[i][j] = 0;
            }
        }

        for(int j:zeroColumnIdx){
            for(int i=0;i<m;i++){
                matrix[i][j] = 0;
            }
        }
    }
}