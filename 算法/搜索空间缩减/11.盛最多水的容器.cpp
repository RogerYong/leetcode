#include <vector>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        if (height.size() < 2)
        {
            return 0;
        }

        int left = 0, right = height.size() - 1;
        int maxWater = 0;
        while (left < right)
        {
            int tmpWater = (right - left) * min(height[left], height[right]);
            maxWater = max(tmpWater, maxWater);
            if (height[left] <= height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxWater;
    }
};