#include <vector>
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        auto n = height.size();
        if (n <= 2)
        {
            return 0;
        }
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        // 左边最高的
        for (int i = 1; i < n; i++)
        {
            left[i] = max(height[i - 1], left[i - 1]);
        }
        // 右边最高的
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(height[i + 1], right[i + 1]);
        }

        int ans = 0;

        // 计算雨水
        for (int i = 1; i < n - 1; i++) // 左右两个是无法接雨水的, 跳过
        {
            int m = min(left[i], right[i]);
            if (m > height[i]) // 形成谷
            {
                ans += m - height[i];
            }
        }
        return ans;
    }
};