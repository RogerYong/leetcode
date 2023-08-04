import java.util.*;

// 
public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 时间复杂度：O(n)，其中n为字符串长度，两次单独的遍历
        空间复杂度：O(1)，哈希表的大小最多不会超过字符集，即52个字符，属于常数空间
     *
     * @param str string字符串
     * @return int整型
     */
    public int FirstNotRepeatingChar (String str) {
        if (str == null || str.isEmpty()) {
            return -1;
        }
        if (str.length() == 1) {
            return 0;
        }



        // write code here
        Map<Character, Integer> charToIdx = new
        HashMap<>(); // 字符第一次出现的idx
        Map<Character, Integer> charToCnt = new HashMap<>(); // 字符出现的次数
        for (int i = 0; i < str.length(); ++i) {
            Character ch = str.charAt(i);
            charToIdx.put(ch, charToIdx.getOrDefault(ch, i));
            charToCnt.put(ch, charToCnt.getOrDefault(ch, 0) + 1);
        }

        int min = -1;
        for (Map.Entry<Character, Integer> entry : charToIdx.entrySet()) {
            Character ch = entry.getKey();
            Integer idx = entry.getValue();

            if (charToCnt.get(ch) == 1) {
                // 只出现1次
                if (min == -1) {
                    min = idx;
                } else {
                    min = Math.min(min, idx);
                }
            }
        }
        return min;
    }
}