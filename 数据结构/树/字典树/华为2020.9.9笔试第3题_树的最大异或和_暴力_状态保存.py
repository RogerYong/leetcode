'''
性质:

(A^B^C^D) ^ (A^B) = C ^ D


数的最大异或和, 这个路径不可能跨越根节点, 只能向下走


暴力+每个节点保存状态是否可行? 时间O(n) 空间O(n2)
理论上可以过的


测试样例
输入
4
1 8 2 3
2 3 -1 -1
3 12 -1 4
4 1 -1 -1
输出
13


输入
5
1 1 2 3
2 4 -1 -1
3 2 -1 4
4 5 -1 5
5 3 -1 -1
输出
7





'''


class TreeNode:
    def __init__(self, id, val):
        self.id = id
        self.val = val
        self.left = None
        self.right = None
        self.scores = None  # 以当前节点为起点的所有路径的异或和

    def get_scores(self):
        if self.scores is not None:
            return self.scores

        self.scores = set()  # 集合去重
        self.scores.add(self.val)

        if self.left is not None:
            left_scores = self.left.get_scores()

            for v in left_scores:
                self.scores.add(self.val ^ v)

        if self.right is not None:
            right_scores = self.right.get_scores()

            for v in right_scores:
                self.scores.add(self.val ^ v)

        return self.scores

    def max_scores(self):
        this_max_scores = max(self.scores)

        if self.left is not None:
            left_max_score = self.left.max_scores()
        else:
            left_max_score = 0

        if self.right is not None:
            right_max_score = self.right.max_scores()
        else:
            right_max_score = 0

        return max(this_max_scores, left_max_score, right_max_score)


def build_tree(nodes, id):
    if id == -1:
        return None
    (_, weight, left_id, right_id) = nodes[id]
    this_node = TreeNode(id, weight)
    this_node.left = build_tree(nodes, left_id)
    this_node.right = build_tree(nodes, right_id)
    return this_node


N = int(input())

nodes = [None] * (N + 1)  # id从1开始

max_score = 0

for i in range(N):
    id, weight, left_id, right_id = [int(_) for _ in input().strip().split()]
    nodes[id] = (id, weight, left_id, right_id)
    if weight > max_score:
        max_score = weight

if N == 1:
    print(nodes[1][1])
    exit()

# 1是根节点
tree = build_tree(nodes, 1)

tree.get_scores()  # 时间O(n), 空间可能比较大, 爆内存?
res = tree.max_scores()  # 时间O(n)
print(res)
