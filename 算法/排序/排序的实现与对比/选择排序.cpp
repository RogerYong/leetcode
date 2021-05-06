#include <vector>
#include <functional>
using namespace std;
template <typename Comparable>
void selectionSort(vector<Comparable> &a)
{
    // 选择排序的最优时间复杂度、平均时间复杂度和最坏时间复杂度均为O(N2)
    // 选择第i小的数, 与数组第i个位置的元素交换
    for (int i = 0; i < a.size() - 1; i++)
    {
        int ith = i;
        for (int j = i + 1; j < a.size(); ++j)
        {
            if (a[ith] > a[j])
            {
                ith = j;
            }
        }
        swap(a[ith], a[i]);
    }
}