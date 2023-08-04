import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param index int整型
     * @return int整型
     */
    public int GetUglyNumber_Solution (int index) {
        // write code here
        if (index == 0) {
            return 0;
        }

        List<Long> nums = new ArrayList<>();
        nums.add(1L);

        // 下一个要乘数的idx
        int idx2 = 0;
        int idx3 = 0;
        int idx5 = 0;

        while (nums.size() < index) {
            Long nextNum2 = nums.get(idx2) * 2;
            Long nextNum3 = nums.get(idx3) * 3;
            Long nextNum5 = nums.get(idx5) * 5;

            Long min = Math.min( Math.min(nextNum2, nextNum3), nextNum5);

            nums.add(min);
            if (min.equals(nextNum2)) {
                idx2++;
            }
            if (min.equals(nextNum3)) {
                idx3++;
            }
            if (min.equals(nextNum5)) {
                idx5++;
            }
        }

        return nums.get(index - 1).intValue();
    }
}