#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        // n - 1 表示把最右边的1变成0, 最右边的1后的0变成1
        // n & (n-1) 表示把最右边的1变成0

        // 之前需要右移31次
        // 利用 n & (n-1), 有k个1, 右移k次
        int cnt = 0;

        while (n)
        {
            cnt++;
            n = n & (n - 1);
        }
        return cnt;
    }
};