public import java.util.*;
public class Solution {



    public int NumberOf1Between1AndN_Solution(int n) {
        int i = 1;
        int base = 1 ;
        int cur = n % 10;
        int high = n / 10;
        int low = 0;

        int cnt = 0;
        for (; cur != 0 ||
                high != 0 ;
                ++i, base = (int) Math.pow(10, i - 1), high = n / base / 10, low = n % base,
                cur = n / base % 10) { // i = 1 表示个位数, i=10 表示10位数
            if (cur == 0) {
                cnt += high * base;
            } else if (cur == 1) {
                cnt += high * base + low + 1;
            } else {
                cnt += (high + 1) * base;
            }
        }
        return cnt;
    }
}