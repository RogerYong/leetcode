// 本质上是斐波那契问题

class Solution
{
public:
    int numWays(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        else if (n == 1)
        {
            return 1;
        }

        int result[110];
        result[0] = 1;
        result[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            result[i] = (result[i - 1] + result[i - 2]) % 1000000007;
        }

        return result[n];
    }
};