'''
腾讯2021 算法岗第二场笔试 第4题

每个圆环有6个数, 无序

两个圆环的6个数相同, 则表示他们相同



思路:


对每个圆环的6个数排序

再对所有圆环排序, 再顺序遍历, 查找相同的圆环

'''


class Circle:
    def __init__(self, l):
        l.sort()
        self.data = l

    def __lt__(self, value):
        for i in range(6):
            if self.data[i] < value.data[i]:
                pass
            else:
                return False

        return True

    def __eq__(self, value):

        for i in range(6):
            if self.data[i] == value.data[i]:
                pass
            else:
                return False

        return True


T = int(input())

for i in range(T):
    n = int(input())
    circles = []
    flag = False
    for i in range(n):
        l = [int(_) for _ in input().strip().split()]
        c = Circle(l)
        circles.append(c)

    if n == 1:
        print('NO')
        continue

    circles.sort()

    flag = False
    for i in range(n - 1):
        if circles[i] == circles[i + 1]:
            flag = True
            break

    if flag:
        print("YES")
    else:
        print("NO")