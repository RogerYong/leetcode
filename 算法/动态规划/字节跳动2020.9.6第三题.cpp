/*
给定一个长为n*⋅m的序列，这个序列是由一个长为n的序列重复m次得来的。

问这个序列的最大连续子段和是多少。(1<=n,m≤10^5)
*/

/*

解析

当m=1时, 就是简单的最大子串和问题(DP法, O(n))

    假设m=1时,  该序列 被分为 三部分 ABC,  其中 B是最大子段,  A段的和<0, C段的和<0

当m>=2时, 

    考虑m=2时
        排列如下:

        012345
        ABCABC

            当B<=0时, 那n*⋅序列的m最大字段和就是B

            当B>0时
                当m>0时,
                dp[0] = A
                dp[1] = B
                dp[2] = B+C
                dp[3] = max( dp[2] + A, A) 
                    当dp[2]=B+C > 0 时, dp[3] = A+B+C
                    当dp[2] <0时, dp[3] = A  < 0
                dp[4] = max (dp[3] +B, B)
                    当dp[3]> 0 时 dp[3] = A+B+C >0, dp[4] = (A+B+C) + B > B

                连续两个串得到了, 比单个串更大的子串和,

                此时的情况是, A+B+C>0


    归纳
        设sum = A+B+C
        当sum> 0, n*m串的最大子段和 =  sum * (m-1) +B
        当sum<0, 最大子段和 = B

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n * 2);
    int64_t ans = LLONG_MIN, dp = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (dp <= 0)
        {
            dp = a[i];
        }
        else
        {
            dp += a[i];
        }
        ans = max(ans, dp);
        sum += a[i];
    }
    if (m == 1)
    {
        cout << ans << '\n';
        return 0;
    }
    int64_t link = LLONG_MIN;
    for (int i = n; i < 2 * n; i++)
    {
        a[i] = a[i - n];
        if (dp <= 0)
        {
            dp = a[i];
        }
        else
        {
            dp += a[i];
        }
        link = max(link, dp);
    }
    if (sum > 0)
    {
        link += 1ll * sum * (m - 2);
    }
    cout << max(link, ans) << '\n';
}