#include <bits/stdc++.h>
using namespace std;

/*

正数的反码是其本身
负数的反码是在其原码的基础上, 符号位不变，其余各个位取反.
为什么需要反码? 用反码来表示减法(计算机只有加法器)

正数的补码就是其本身
负数的补码是在其原码的基础上, 符号位不变, 其余各位取反, 最后+1. (即在反码的基础上+1)


为什么需要补码?
为了
在原码中, +0 是 00000000, -0是 10000000

0怎么可以存在两种,计算方式?

对-0的原码符号位不变, 其他位取反, 得 11111111, 再 +1 , 则会得到00000000, 即+0
至此, -0和+0的

补码的过程, 使得+0/-0统一, 从而统一正数负数的计算,


再补码的计算过程中, 产生一个操作,反码

+0 -0统一以后, 补码多出了一个位置, 1000 0000, 这个不能通过8位的反码+1计算得到, 但是如果算9位. 这就用来表示额外的负数, -128
-128的9位原码 1 1000 0000, 补码正好是 1 1000 0000.







*/

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int ans = 0;
        int sign = (dividend ^ divisor) < 0 ? -1 : 1;

        // 边界
        if (divisor == INT_MIN)
        {
            if (dividend == INT_MIN)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if (dividend == INT_MIN)
        {
            if (divisor == -1) // 溢出
            {
                return INT_MAX;
            }
            else if (divisor == 1)
            {
                return INT_MIN;
            }

            dividend += abs(divisor); // 后面需要把dividend转换为正数, 避免溢出
            ans++;
        }

        // 转正数
        dividend = abs(dividend);
        divisor = abs(divisor);

        while (divisor <= dividend)
        {
            int tmp_ans = 1;
            int tmp_divisor = divisor;
            while (tmp_divisor < (dividend >> 1)) // 避免溢出
            {
                tmp_divisor <<= 1;
                tmp_ans <<= 1;
            }

            ans += tmp_ans;
            dividend -= tmp_divisor;
        }
        return sign * ans;
    }
};

int main()
{
    Solution s;
    s.divide(10, 3);
}