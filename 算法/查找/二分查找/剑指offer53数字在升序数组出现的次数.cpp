#include <algorithm>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @param k int整型 
     * @return int整型
     */
    int GetNumberOfK(vector<int>& nums, int k) {
        // write code here
        auto l = lower_bound(nums.begin(), nums.end(),k);
        auto r = upper_bound(nums.begin(), nums.end(),k);
        return r - l;
    }
};