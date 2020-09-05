// 快速幂
// x^n  如果 n=2k, 那 x^n = (x^2)^k
// 复杂度从 O(n) 降到 O(logn)
// 这只考虑exp是正整数的情况, 没有考虑负数
// 负数情况下, x^n,  =  1/ (x^(-n))

long long fast_pow(long long base, long long exp, long long mod)
{
    if (exp == 0)
    {
        return 1;
    }
    long long ans = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp & 1) // 奇数
        {
            ans = (ans * base) % mod;
        }
        // 现在exp为偶数
        exp = exp >> 1; // 右移1位,相当于/2
        base = (base * base) % mod;
    }
    return ans;
}
long long fast_pow(long long base, long long exp)
{
    if (exp == 0)
    {
        return 1;
    }
    long long ans = 1;
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