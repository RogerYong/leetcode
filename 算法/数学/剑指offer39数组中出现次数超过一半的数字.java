/*
 * 
 * 方法一: hash表, 时间复杂度O(N), 空间复杂度O(N)
 * 方法二: 排序后取数组中间的那个数, 即众数. 时间复杂度O(nlogn), 空间复杂度O(1)
 * 方法三: 选举法. 如果两个数不相等, 则消去这两个数. 时间复杂度O(N), 空间复杂度O(1)
 * 
 */
import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型一维数组
     * @return int整型
     */
    public int MoreThanHalfNum_Solution (int[] numbers) {
        // write code here
        if (numbers == null) {
            return 0;
        }
        int cood = -1;
        int cnt = 0;

        for (int i = 0; i < numbers.length; ++i) {
            if (cnt == 0) {
                cood = numbers[i];
                cnt = 1;
            } else {
                if (numbers[i] == cood) {
                    cnt += 1;
                } else {
                    cnt -= 1;
                }
            }
        }
        // 如果不保证有解
        cnt = 0;
        for ( int k : numbers) {
            if (k == cood) {
                cnt ++;
            }
        }
        if (cnt > numbers.length / 2) {
            return cood;
        }
        return -1;
    }
}