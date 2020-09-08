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

            vis[i][j] = True
            for c in coors:
                res_cp = res.copy()
                res_cp.append((i, j))
                tmp_res = dfs(x + c[0], y + c[1], res_cp)
                if len(tmp_res) == n * n:
                    return tmp_res
            vis[i][j] = False
            return res
        else:
            return res

    res = dfs(x, y, [])
    if len(res) == n * n:
        print(True)
        # 打印res
    else:
        print(False)
