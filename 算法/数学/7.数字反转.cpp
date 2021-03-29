class Solution
{
public:
    int reverse(int x)
    {
        int upper = 214748364; // 7 , 8
        int res = 0;
        while (x != 0)
        {
            int m = x % 10; // 个位
            x /= 10;        // 高位

            if (res > 214748364 || (res == 214748364 && m > 7))
            {
                return 0;
            }
            if (res < -214748364 || (res == -214748364 && m < -8))
            {
                return 0;
            }
            res = res * 10 + m;
        }
        return res;
    }
};