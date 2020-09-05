#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int hammingWeight(uint32_t m)
    {
        // 因为这是无符号整数
        // 直接右移即可
        int cnt = 0;
        while (m)
        {
            if (m & 1)
            {
                cnt++;
            }
            m = m >> 1;
        }
        return cnt;
    }
};