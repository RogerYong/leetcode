'''
'''


from typing import List


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        if not tasks or len(tasks)<=1:
            return len(tasks)

        
        # 统计
        task_to_cnt = dict()
        for t in tasks:
            task_to_cnt[t] = task_to_cnt.get(t, 0) + 1

        # 排序
        cnt_sort = sorted(task_to_cnt.values(), reverse=True)

        max_cnt = cnt_sort[0]

        t = (max_cnt-1) * (n+1)

        for cnt in cnt_sort:
            if cnt == max_cnt:
                t += 1
        
        if t < len(tasks):
            return len(tasks)
        else:
            return t

if __name__ == "__main__":
    cases = [
        ( ["A","A","A","B","B","B"], 2,8),
        ( ["A","A","A","B","B","B"], 0, 6),
        (["A","A","A","A","A","A","B","C","D","E","F","G"],2,16)
    ]
    s = Solution()
    for tasks, n, ans in cases:
        res = s.leastInterval(tasks,n)
        print(ans, res)