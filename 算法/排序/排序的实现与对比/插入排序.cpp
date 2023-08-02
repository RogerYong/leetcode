#include <vector>
#include <functional>
using namespace std;
template <typename Comparable>
void insertionSort(vector<Comparable> &a)
{
    // 最坏时间复杂度O(n2)
    // 最好 O(N): 如果数据已经排好序
    // 平均O(n2)
    int j;
    for (int p = 1; p < a.size(); p++) // N-1趟排序
    {

        // 对于第p趟排序的结果, 保证[0,p)是有序的

        // 因此, 第p趟排序, 选择下标为p的数,在前面[0,p-1]插入

        Comparable tmp = a[p];
        for (j = p; j > 0 && tmp < a[j - 1]; j--) // 从后往前比较, 同时挪动数组
        {
            a[j] = a[j - 1];
        }
        a[j] = tmp;
    }
}

// 下面是STL实现, 一个通用的插入排序实现

template <typename Iterator>
void insertionSort(const Iterator &begin, const Iterator &end)
{
    if (begin != end)
    {
        insertionSortHelp(begin, end, *begin);
    }
}

template <typename Iterator, typename Object>
void insertionSortHelp(const Iterator &begin, const Iterator &end, Object &obj)
{
    insertionSort(begin, end, less<Object>());
}
template <typename Iterator, typename Comparator>
void insertionSort(const Iterator &begin, const Iterator &end, Comparator lessThan)
{
    if (begin != end)
    {
        insertionSort(begin, end, lessThan, *begin);
    }
}

template <typename Iterator, typename Comparator, typename Object>
void insertionSort(const Iterator &begin, const Iterator &end, Comparator lessThan, Object &obj)
{
    // 上面是辅助函数
    // 这里是真正的实现
    Iterator j;
    for (Iterator p = begin + 1; p != end; ++p)
    {
        Object tmp = *p;
        for (j = p; j != begin && lessThan(tmp, *(j - 1)); --j)
        {
            *j = *(j - 1);
        }
        *j = tmp;
    }
}