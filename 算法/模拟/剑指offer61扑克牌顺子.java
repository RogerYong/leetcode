import java.util.*;

public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型一维数组
     * @return bool布尔型
     */
    public boolean IsContinuous(int[] numbers) {
        // write code here
        int min = 0;
        int max = 0;
        Set<Integer> s = new HashSet<>();
        for (int num : numbers) {
            if (num != 0) {
                if (s.contains(num)) {
                    return false;
                } else {
                    s.add(num);
                }
                min = min == 0 ? num : Math.min(min, num);

                max = max == 0 ? num : Math.max(max, num);
            }
        }

        return max - min <= 4;
    }
}