#include <vector>
#include <functional>
using namespace std;
template <typename Comparable>
void shellSort(vector<Comparable> &a)
{
    // 最坏 O(N2)
    // 平均 
    for (int gap = a.size() / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < a.size(); i++)
        {
            Comparable tmp = a[i];
            int j = i;
            for (; j >= gap && tmp < a[j - gap]; j -= gap)
            {
                a[j] = a[j - gap];
            }
        }
    }
}