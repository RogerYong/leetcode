// n可以是负数
#include <iostream>
using namespace std;

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

class Solution
{
public:
    double myPow(double x, int n)
    {
        // 特殊情况
        if (x == 0.0 || n == 1 || x == 1.0)
        {
            return x;
        }

        if (n == 0)
        {
            return 1;
        }

        if (n > 0)
        {
            return fast_pow(x, n);
        }
        else // n < 0
        {
            long long exp = n; // n = INT_MIN时, -n会溢出, 所有需要 long

            return 1.0 / fast_pow(x, -exp);
        }
    }
};

int main()
{
    double x = 1;
    int exp = INT32_MIN;
    Solution s = Solution();
    cout << s.myPow(x, exp);
    return 0;
}