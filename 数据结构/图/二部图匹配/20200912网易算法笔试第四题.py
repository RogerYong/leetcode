def dfs(boy_id):
    for girl_id in girl_ids:
        if girl_id in boy_to_girl[boy_id] and (not girl_vis[girl_id]):
            girl_vis[girl_id] = True
            if girl_res[girl_id] is None or dfs(girl_res[girl_id]):
                girl_res[girl_id] = boy_id
                return True

    return False


line = input()
boy_ids = [int(_) for _ in line.strip().split()]
line = input()
girl_ids = [int(_) for _ in line.strip().split()]

n = int(input())

boy_to_girl = {}
for boy_id in boy_ids:
    boy_to_girl[boy_id] = []

girl_res = {}  # 保存这个女孩匹配的boy
for girl_id in girl_ids:
    girl_res[girl_id] = None  # None表未匹配

girl_vis = {}  # 表示是否已经被占用
for girl_id in girl_ids:
    girl_vis[girl_id] = False

for i in range(n):
    line = input()
    line_int = [int(_) for _ in line.strip().split()]
    tmp_boy_id = line_int[0]
    tmp_girl_id = line_int[1]
    boy_to_girl[tmp_boy_id].append(tmp_girl_id)

cnt = 0
for boy_id in boy_ids:
    for girl_id in girl_ids:
        girl_vis[girl_id] = False
    if dfs(boy_id):
        cnt += 1

print(cnt)