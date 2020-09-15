'''
2020/9/15 阿里笔试第二题

输入两个01串, 求最短公共非子序列的长度


贪心法:

第一步: 分别计算, 两个字符串的最短非子序列长, 及剩余字符

把字符串S, 划分为 A1 A2 A3 ... Ak B

Ai表示包含0,1的连续区间,可以是0+1, 1+0

B表示剩余字符, 只包含0*, 或只包含1*, 或者为空

那S的最短非子序列长为k+1


第二步: 计算最短公共非子序列

测试用例

输入
0
1
输出
2

'''


def shortest_non_subseq(s):
    '''
    返回最短非子序列的长度, 及剩余字符
    '''
    flag = {}
    flag['0'] = False
    flag['1'] = False
    last_char = None

    range_cnt = 1
    for i, c in enumerate(s):
        if i == 0:
            last_char = c
        flag[c] = True

        if flag['0'] and flag['1']:
            range_cnt += 1
            flag['0'] = False
            flag['1'] = False
            if i == len(s) - 1:
                last_char = None
            else:
                last_char = s[i + 1]

    return range_cnt, last_char


s1 = input()
s2 = input()

sns1, last_char1 = shortest_non_subseq(s1)
sns2, last_char2 = shortest_non_subseq(s2)

if sns1 == sns2 and (last_char1, last_char2) in [('0', '1'), ('1', '0')]:
    ans = sns1 + 1
else:
    ans = max(sns1, sns2)
print(ans)

# 记录剩余字符, 就可以把最短公共非子序列打印出来
