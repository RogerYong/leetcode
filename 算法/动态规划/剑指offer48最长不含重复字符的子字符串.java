import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return int整型
     */
    public int lengthOfLongestSubstring (String s) {
        if (s == null || s.isEmpty()) {
            return 0 ;
        }

        // write code here
        int max = 1; // 最大值
        int curLen =
            1;  // 以s[i]结尾的最长不含重复字符的子字符串长度
        Map<Character, Integer> charToIdx = new HashMap<>();
        charToIdx.put(s.charAt(0), 0);
        for (int i = 1; i < s.length(); ++i) {
            Character ch = s.charAt(i);
            if (charToIdx.containsKey(ch)) {
                int prevIdx = charToIdx.get(ch);
                for (int j = i - curLen; j <= prevIdx; ++j ) {
                    charToIdx.remove(s.charAt(j));
                }
                curLen = i - prevIdx;
            } else {
                curLen = curLen + 1;
            }
            charToIdx.put(ch, i);
            max = Math.max(max, curLen);
        }
        return max;
    }
}