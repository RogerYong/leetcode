// 快速幂
// x^n  如果 n=2k, 那 x^n = (x^2)^k
// 复杂度从 O(n) 降到 O(logn)

long long fast_pow(long long base, long long exp, long long mod)
{
    if (exp == 0)
    {
        return 1;
    }
    long long ans = 1;
    long long base = base % mod;
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