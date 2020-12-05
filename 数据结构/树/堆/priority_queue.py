import heapq
from queue import PriorityQueue


class Node:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __lt__(self, value):
        return self.x < value.x  # 修改这个可以实现大顶堆
        # return self.x > value.x  # 修改这个可以实现大顶堆

    def __str__(self):
        return "({}, {})".format(self.x, self.y)

    def __repr__(self):
        return self.__str__()


def test_heapq():
    data = [1, 213, 34, 12, 35, 23, 546]

    # top k最大
    print(heapq.nlargest(3, data))

    # top k 最小
    print(heapq.nsmallest(3, data))

    # 在list上做堆的操作
    heapq.heapify(data)  # 小顶堆, 使用push/pop之前, 需要heapify
    print(data)

    # 向堆中插入数据, 并维护数据
    heapq.heappush(data, 30)  # 要求这个list是已经建好的堆
    print(data)

    print('Pop')
    print(heapq.heappop(data))  # 弹出小顶堆
    print(data)


def test_PriorityQueue():
    q = PriorityQueue()
    q.put(Node(1, 2))
    q.put(Node(92, 2))
    q.put(Node(34, 2))
    q.put(Node(64, 2))
    q.put(Node(5, 2))
    q.put(Node(6, 2))

    print(q.queue)


def main():
    # test_heapq()
    test_PriorityQueue()


if __name__ == "__main__":
    main()
