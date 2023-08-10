import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return int整型
     */
    public int StrToInt (String s) {
        // write code here

        if (s == null) {
            return 0;
        }

        s = s.trim();
        if(s.isEmpty()){
            return 0;
        }
        int sign = 1;

        if (s.charAt(0) == '+') {
            s = s.substring(1);
        } else if (s.charAt(0) == '-') {
            sign = -1;
            s = s.substring(1);
        }

        // s= s.trim();
        int i = 0;
        long ans = 0;
        long tmp = 0;

        while (i < s.length() && s.charAt(i) >= '0' && s.charAt(i) <= '9') {
            tmp = ans * 10 + (s.charAt(i) - '0');

            if (sign * tmp > Integer.MAX_VALUE) {
               return Integer.MAX_VALUE;           
            }
            if (sign * tmp < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;
            }
            ans = tmp;
            i++;
        }
        return (int) (sign * ans);
    }
}