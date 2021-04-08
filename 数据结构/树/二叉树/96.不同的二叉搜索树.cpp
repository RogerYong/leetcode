#include <vector>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        vector<int> nums(n + 1, 0);
        nums[0] = 1;
        nums[1] = 1;
        nums[2] = 2;

        for (int i = 3; i <= n; i++)
        {
            for (int j = 1; j <= i; ++j)
            {
                nums[i] += nums[j - 1] * nums[i - j];
            }
        }
        return nums[n];
    }

    
};

int main()
{
    auto s = Solution();
    int ret = s.numTrees(100);
    return ret;
}