import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return int整型
     */
    public int findNthDigit (int n) {
        if (n < 10) {
            return n;
        }
        // write code here
        // 第一步, 确定几位数
        int nDigit = 1;
        long charCnt = 9 * (long)Math.pow(10, nDigit - 1) * nDigit; // 注意用long, 不然会溢出

        // [min, max]
        // [1, 9]
        // [10, 90]
        // [100, 900]

        while (n > charCnt ) {
            n -= charCnt;
            nDigit += 1;
            charCnt = 9 * (long)Math.pow(10, nDigit - 1) * nDigit;
        }
        // System.out.println(nDigit);
        // System.out.println(charCnt);
        // System.out.println(n);

        // 确定是哪一个数
        long min = (long)Math.pow(10, nDigit - 1);
        System.out.println("min"+ min);
        long order = (n - 1) / nDigit;
        // System.out.println(order);
        long num = min + order;
        String s = String.valueOf(num);

        // 确定第几个数字
        int idx = (n - 1) % nDigit;

        return (int)s.charAt(idx) - (int) '0';
    }
}