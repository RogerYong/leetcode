#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        if (!(&numbers) || numbers.size() == 0)
        {
            return 0;
        }
        if (numbers.size() == 1)
        {
            return numbers[0];
        }

        vector<int>::size_type left = 0;
        vector<int>::size_type right = numbers.size() - 1;

        while (left < right)
        {
            auto mid = left + (right - left) / 2;
            if (numbers[mid] < numbers[right])
            {
                right = mid;
            }
            else if (numbers[mid] > numbers[right])
            {
                left = mid + 1;
            }
            else
            {
                right = right - 1;
            }
        }

        return numbers[left];
    }
};