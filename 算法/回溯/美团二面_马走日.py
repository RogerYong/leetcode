'''
n*n 的棋盘

给定(x,y)起点

马走日的方式,

请问,能够不重复地走完整个棋盘
'''

coors = [
    (-2, 1),
    (-1, 2),
    (1, 2),
    (2, 1),
    (2, -1),
    (1, -2),
    (-1, -2),
    (-2, -1),
]


def solve(n, x, y) -> int:
    vis = [[False] * n for i in range(n)]

    # 找n*n的走法
    def dfs(i, j, res):
        if 0 <= i < n and 0 <= j < n and (not vis[i][j]):
            res.append((i, j))
            if len(res) == n * n:
                return

            vis[i][j] = True
            for a, b in coors:
                dfs(i + a, j + b, res)
                if len(res) == n * n:
                    return
            vis[i][j] = False
            res.pop()
            return
        else:
            return

    a_path = []
    dfs(x, y, a_path)
    if len(a_path) == n * n:
        print(True)
        print(a_path)
    else:
        print(False)


solve(5, 2, 2)
