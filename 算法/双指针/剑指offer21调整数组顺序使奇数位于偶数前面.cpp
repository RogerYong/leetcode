#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        // 两个条件对应的lambda函数
        auto even_lambda = [](int x) { return x % 2 == 0; };
        auto odd_lambda = [](int x) { return x % 2 == 1; };

        // 从前往后找偶数
        auto even_it = find_if(nums.begin(), nums.end(), even_lambda);

        // 从后往前找奇数
        auto reversed_odd_it = find_if(nums.rbegin(), nums.rend(), odd_lambda);

        if (even_it == nums.end() || reversed_odd_it == nums.rend())
        {
            return nums;
        }
        auto odd_it = reversed_odd_it.base() - 1;
        int tmp;
        while (even_it != nums.end() && reversed_odd_it != nums.rend())
        {
            odd_it = reversed_odd_it.base() - 1;
            if (even_it < odd_it) // 存在偶数在奇数前
            {
                // 交换
                tmp = *even_it;
                *even_it = *odd_it;
                *odd_it = tmp;

                // 更新迭代器
                even_it = find_if(even_it + 1, nums.end(), even_lambda);
                reversed_odd_it = find_if(reversed_odd_it + 1, nums.rend(), odd_lambda);
            }
            else
            {
                break;
            }
        }
        return nums;
    }
};

int main()
{
    Solution s;
    vector<int> v{1, 2, 3, 4};
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << endl;
    }
    s.exchange(v);
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << endl;
    }
}