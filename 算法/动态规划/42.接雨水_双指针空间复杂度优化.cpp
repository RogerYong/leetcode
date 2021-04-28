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
        int left = 0;
        int right = n - 1;
        int max_left = 0;
        int max_right = 0;

        int ans = 0;

        // 计算雨水
        while (left < right)
        {
            // 维护left_max, right_max
            max_left = max(max_left, height[left]);
            max_right = max(max_right, height[right]);

            if (max_left < max_right)
            {
                ans += max_left - height[left];
                left++;
            }
            else
            {
                ans += max_right - height[right];
                right--;
            }
        }

        return ans;
    }
};