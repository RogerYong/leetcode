import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param grid int整型二维数组
     * @return int整型
     */
    public int maxValue (int[][] grid) {
        // write code here
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        // dp
        List<List<Integer>> dp = new ArrayList<>();
        for (int i = 0; i < grid.length; ++i) {
            List<Integer> line = new ArrayList<>();
            for (int j = 0; j < grid[0].length; ++j) {
                
                if (i == 0) {
                    if (j == 0) {
                        line.add(grid[i][j]);
                    } else {
                        line.add( line.get(j - 1) + grid[i][j]);
                    }
                } else {
                    if (j == 0) {
                        line.add(dp.get(i - 1).get(j) + grid[i][j]);
                    } else {
                        // 状态转移方程
                        line.add( Math.max( line.get(j - 1),
                                            dp.get(i - 1).get(j) ) + grid[i][j]  );
                    }
                }
            }
            dp.add(line);
        }
        return dp.get(grid.length-1).get(grid[0].length-1);
    }
}