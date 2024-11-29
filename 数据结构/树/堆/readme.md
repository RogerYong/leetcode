# 优先队列
优先队列也是一种队列. 

普通队列的出队顺序是先进先出, 

优先队列的出队顺序则是按照优先级来的, 故称为优先队列.


使用大根堆, 小根堆可实现优先队列.

# 大根堆 小根堆

堆 heap, 一种特殊性质的二叉树.

## 堆的性质
* 堆中所有结点的值必须大于或等于（或小于或等于）其孩子结点的值
* 堆应该是一颗完全二叉树. 完全二叉树, 就是当 h > 0 时，所有叶子结点都处于第 h 或 h - 1 层(其中 h 为树的高度)

## 通常用一个数组实现堆

### 堆的push

数据插入数组尾部, 并shift up

时间复杂度O(log(n))


### 堆的pop

弹出堆顶后, 把数组尾部的数据放回堆顶, 并shift down

时间复杂度O(log(n))

### 堆查找某一个元素
时间复杂度O(n)

### 堆的replace

先取出堆顶, 再插入一个元素

常规做法: 先pop 再push, 2 * O(logn)

优化方法: 元素与堆顶交换, 再对堆顶shift down

### 堆化Heapify 从一个数组创建堆

把数组看做完全二叉树, 从最后一个非叶子节点往前shift_down


# python优先队列
python的优先队列有两种实现: 
```
import heapq
from queue import PriorityQueue
```
# c++ 优先队列
```
priority_queue<int, vector<int>, greater<int>> q1; // 小顶堆
priority_queue<int, vector<int>, less<int>> q2;    // 大顶堆
```

# java
```
PriorityQueue<Integer> pq = new PriorityQueue<>(); // 小顶堆
PriorityQueue<Integer> pq2 = new PriorityQueue<>((a, b) -> b - a); // 大顶堆
```