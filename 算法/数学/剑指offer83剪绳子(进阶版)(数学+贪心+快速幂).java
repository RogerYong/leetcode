import java.util.*;

// 注意 当mod >= sqrt(Long.MAX_VALUE) = 3.03700049997605E9, 约 30亿, 会溢出
// 需要使用加法代替乘法, 避免溢出


public class Solution {

    /**
        计算 a*b % mod
     */
    public long mul(long a, long b, long mod) {
        long ans = 0;


        a = a % mod;
        b = b % mod;

        while (b != 0) {
            if ((b & 1) != 0) {
                ans = (ans + a ) % mod;
            }
            b = b >> 1;
            a = (a << 1) % mod;
        }

        return ans;
    }

    long MOD = 998244353;

    /**
    计算 base ^ exp % mod
     */
    public long pow(long base, long exp, long mod) {
        if (exp == 0) {
            return 1;
        }
        long ans = 1;
        base = base % mod;
        while (exp > 0) {
            if ((exp & 1) != 0) {
                // exp是奇数
                ans =  mul(ans, base, mod); 

            }
            // 现在exp是偶数,exp= exp/2, base=base^2
            exp = exp >> 1;
            base =  mul(base, base, mod);
        }
        return ans;
    }


    public long cutRope (long number) {
        // number > 1
        if (number <= 3) {
            return number - 1;
        }

        if (number % 3 == 0) {
            return pow(3, number / 3, MOD);
        } else if (number % 3 == 1) {

            return mul( pow(3, (number - 4) / 3, MOD), 4, MOD);
      
        } else {
            return mul(pow(3, (number - 2) / 3, MOD),2, MOD);
        }
    }
}