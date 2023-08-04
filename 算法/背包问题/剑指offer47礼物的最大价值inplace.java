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
        int h = grid.length;
        int w = grid[0].length;

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (i == 0) {
                    if (j != 0) {
                        grid[i][j] = grid[i][j - 1] + grid[i][j];
                    }
                } else {
                    if (j == 0) {
                        grid[i][j] = grid[i - 1][j] + grid[i][j];
                    } else {
                        // 状态转移方程
                        grid[i][j] = Math.max(grid[i][j - 1], grid[i - 1][j] ) + grid[i][j];
                    }
                }
            }
        }
        return grid[h - 1][w - 1];
    }
}