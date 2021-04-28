// 原地Hash

// 长N的数组, 所有正整数[1,N+1)
// 把所有<=0的数, 改成N+1
// 这样就能用符号来表示Hash
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        int up = n + 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= 0)
            {
                nums[i] = up;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int tmp = abs(nums[i]);
            if (tmp >= 1 && tmp <= n) // [1,N]
            {
                nums[tmp - 1] = -abs(nums[tmp - 1]); // 设为负数
            }
        }
        int target = up;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                target = i + 1;
                break;
            }
        }
        return target;
    }
};