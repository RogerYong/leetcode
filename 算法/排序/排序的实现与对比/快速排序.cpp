#include <vector>
#include <functional>
using namespace std;
template <typename Comparable>
void quickSort(vector<Comparable> &a)
{
    quicksort(a, 0, a.size() - 1);
}

// 选择中间数
template <typename Comparable>
const Comparable &median3(vector<Comparable> &a, int left, int right)
{
    int center = (left + right) / 2;
    if (a[center] < a[left])
    {
        swap(a[left], a[center]);
    }
    if (a[right] < a[left])
    {
        swap(a[left], a[right]);
    }
    if (a[right] < a[center])
    {
        swap(a[center], a[right]);
    }

    // a[center]是pivot
    swap(a[center], a[right - 1]); // 把pivot放在a[right-1]
    return a[right - 1];
}

template <typename Comparable>
void insertionSort(vector<Comparable> &a, int left, int right)
{
    // 最坏时间复杂度O(n2)
    // 最好 O(N): 如果数据已经排好序
    // 平均O(n2)
    int j;
    for (int p = left + 1; p <= right; p++) // N-1趟排序
    {

        // 对于第p趟排序的结果, 保证[left,p]是有序的

        // 因此, 第p趟排序, 选择下标为p的数,在前面[left,p-1]插入

        Comparable tmp = a[p];
        for (j = p; j > left && tmp < a[j - 1]; j--) // 从后往前比较, 同时挪动数组
        {
            a[j] = a[j - 1];
        }
        a[j] = tmp;
    }
}

template <typename Comparable>
void quicksort(vector<Comparable> &a, int left, int right)
{
    if (left + 10 <= right) // 比较大的数组
    {
        Comparable pivot = median3(a, left, right);

        // 数组划分
        int i = left, j = right - 1;
        for (;;)
        {
            while (a[++i] < pivot)
            {
            }
            while (pivot < a[--j])
            {
            }
            if (i < j)
            {
                swap(a[i], a[j]);
            }
            else
            {
                break;
            }
        }

        swap(a[i], a[right - 1]);
        quicksort(a, left, i - 1);
        quicksort(a, i + 1, right);
    }
    else
    {
        // 小数组
        // 使用插入排序
        insertionSort(a, left, right);
    }
}