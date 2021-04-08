class Solution
{
public:
    double myPow(double x, int n)
    {
        long long N = n; // 有符号int, 取反, 必须使用long long, 避免溢出

        return N >= 0 ? fast_pow(x, N) : (1 / fast_pow(x, -N));
    }

    double fast_pow(double base, long long exp)
    {
        if (exp == 0)
        {
            return 1;
        }
        double ans = 1.0;
        while (exp > 0)
        {
            if (exp & 1) // 奇数
            {
                ans = ans * base;
            }
            // 现在exp为偶数
            exp = exp >> 1; // 右移1位,相当于/2
            base = base * base;
        }
        return ans;
    }
};