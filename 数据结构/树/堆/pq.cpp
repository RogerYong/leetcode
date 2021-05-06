// 一个基于vector的heap实现

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void heap_push(vector<int> &heap, int value)
{
    // 时间复杂度 O(logN)
    // value是需要插入的数值

    // heap 一个大顶堆

    heap.push_back(value);          // 增加一个hole
    int hole_idx = heap.size() - 1; // 当前的洞的位置

    int parent_idx = (hole_idx - 1) / 2;
    while (hole_idx > 0 && heap[parent_idx] < value)
    {
        // 循环内使用了<, 因此是大顶堆
        // 如果使用>, 是小顶堆

        heap[hole_idx] = heap[parent_idx]; // 用父节点来填充洞

        // 洞上移
        hole_idx = parent_idx;
        parent_idx = (hole_idx - 1) / 2;
    }
    heap[hole_idx] = value;
};

void shift_down(vector<int> &heap, int hole_idx)
{
    // 在hole_idx处的是新替换进来的数
    // 其左右孩子是正确的,
    // 需要进行调整(下沉操作)
    int second_child_idx = hole_idx * 2 + 2;

    while (second_child_idx < heap.size())
    {
        if (heap[hole_idx] >= max(heap[second_child_idx], heap[second_child_idx - 1]))
        {
            break;
        }
        else
        {
            // 选个大的交换
            if (heap[second_child_idx] < heap[second_child_idx - 1])
            {
                second_child_idx--;
            }
            swap(heap[hole_idx], heap[second_child_idx]);

            hole_idx = second_child_idx;
            second_child_idx = hole_idx * 2 + 2;
        }
    }
    if (second_child_idx == heap.size()) // 没有右节点, 有左节点
    {
        if (heap[hole_idx] < heap[second_child_idx - 1])
        {
            swap(heap[hole_idx], heap[second_child_idx - 1]);
        }
    }
}

int heap_pop(vector<int> &heap)
{
    // 时间复杂度O(logN)
    if (heap.empty())
    {
        return 0;
    }

    int result = heap[0];
    heap[0] = heap.back(); // 堆中最后一个节点的值, 移动到根节点
    heap.pop_back();
    shift_down(heap, 0);
    return result;
}

void heap_make(vector<int> &heap)
{
    // 复杂度O(N)
    // 找到最后一个非叶子节点的下标 last_parent = heap.size() / 2 - 1
    //  for i: last_parent -> 0
    // 自下往上地维护
    int idx = heap.size() / 2 - 1;
    for (int i = idx; i >= 0; i--)
    {
        shift_down(heap, i);
    }
}

vector<int> heap_sort(vector<int> &heap)
{
    // 从大到小排序 O(NlogN)

    // 每次弹出最大值, 然后
    vector<int> ans;
    while (!heap.empty())
    {
        ans.push_back(heap_pop(heap));
    }
    return ans;
}

void print_list(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}
void print_list(vector<int> &&v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ' ';
    }
    cout << endl;
}
int main()
{
    int ia[9] = {0, 1, 2, 3, 4, 8, 9, 3, 5};
    vector<int> iv1(ia, ia + 9), iv2(ia, ia + 9);

    heap_make(iv1);
    make_heap(iv2.begin(), iv2.end());

    print_list(iv1);
    print_list(iv2);

    cout << "=" << endl;

    heap_push(iv1, 7);
    iv2.push_back(7);
    push_heap(iv2.begin(), iv2.end());

    print_list(iv1);
    print_list(iv2);

    cout << "=" << endl;

    cout << heap_pop(iv1) << endl;
    print_list(iv1);

    pop_heap(iv2.begin(), iv2.end());
    cout << iv2.back() << endl;
    iv2.pop_back();
    print_list(iv2);

    cout << "=" << endl;

    print_list(heap_sort(iv1));
    sort_heap(iv2.begin(), iv2.end());
    print_list(iv2);

    return 0;
}