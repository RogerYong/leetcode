#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

inline int leftChild(int i)
{
    return 2 * i + 1;
}
template <typename Comparable>
void percDown(vector<Comparable> &a, int i, int n)
{
    int child;
    Comparable tmp = a[i];
    for (; leftChild(i) < n; i = child)
    {
        child = leftChild(i);
        if (child != n - 1 && a[child] < a[child + 1])
        {
            child++;
        }
        if (tmp < a[child])
        {
            a[i] = a[child];
        }
        else
        {
            break;
        }
    }
    a[i] = tmp;
}
template <typename Comparable>
inline void heap_make(vector<Comparable> &heap)
{
    // 复杂度O(N)
    // 找到最后一个非叶子节点的下标 last_parent = heap.size() / 2 - 1
    //  for i: last_parent -> 0
    // 自下往上地维护

    for (int i = heap.size() / 2; i >= 0; i--)
    {
        percDown(heap, i, heap.size());
    }
}
template <typename Comparable>
void heap_sort(vector<Comparable> &heap)
{
    // 建堆
    heap_make(heap);
    // 从大到小排序 O(NlogN)

    // 每次弹出最大值, 然后

    for (int j = heap.size() - 1; j > 0; j--)
    {
        swap(a[0], a[j]); // 把最大值放在最后, 并把最后的值插入根部
        percDown(heap, 0, j);
    }
}