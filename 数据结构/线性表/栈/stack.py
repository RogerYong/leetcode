# python中的stack是 后进先出队列

from queue import LifoQueue


def main():
    stack = LifoQueue()  # 默认无容量限制
    # stack = LifoQueue(maxsize) # 限制容量
    # stack.qsize() # 当前容量
    # stack.full() # 判断是否达到容量
    for i in range(5):
        stack.put(i)

    while not stack.empty():
        print(stack.get())


if __name__ == "__main__":
    main()