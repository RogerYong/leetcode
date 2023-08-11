# 队列与双端队列
队列Queue
双端队列Deque

# C++队列
std::deque<T>
std::queue<T>


# python 队列
```
from queue import Queue
from collections import deque
```


# java队列/双端队列

## 队列Queue
### 非阻塞队列
####  优先队列 PriorityQueue
```
```
PriorityQueue<Integer> pq = new PriorityQueue<>(); // 小顶堆
PriorityQueue<Integer> pq2 = new PriorityQueue<>((a, b) -> b - a); // 大顶堆
```
```
#### 并发队列 ConcurrentLinkedQueue

### 阻塞队列 BlockingQueue 

阻塞队列在前面的队列定义基础上增加了以下几个方法，来支持阻塞操作。

take：取出并移除元素，如队列为空则一直阻塞直到有元素；
put：插入元素，如队列满则一直阻塞直到有空位可以插入元素；
可超时的offer：插入元素并指定超时时间，如队列满等待指定的时间；
可超时的poll：取出并移除元素，如队列空等待指定的时间。

无界: 无大小限制

DelayQueue 无界延时队列 

SynchronousQueue 同步队列, 没有size概念. 元素时会一直阻塞直到有另一个线程取元素，取元素同样会一直阻塞直到有另一个线程插入元素。

LinkedBlockingQueue  基于链表实现的有界的阻塞队列

ArrayBlockingQueue 基于数组实现的有界的阻塞队列

PriorityBlockingQueue 无界优先级阻塞队列

## 双端队列

LinkedList
ArrayDeque
ConcurrentLinkedDeque 
LinkedBlockingDeque



