def get_next(pat):
    len_pat = len(pat)
    next_list = [0] * (len_pat + 1)
    next_list[0] = -1

    k = -1
    j = 0
    while j < len_pat - 1:
        if k == -1 or pat[j] == pat[k]:
            k += 1
            j += 1
            if pat[j] != pat[k]:
                next_list[j] = k
            else:
                next_list[j] = next_list[k]
        else:
            k = next_list[k]
    return next_list


def kmp(s, pat):
    next_list = get_next(pat)

    len_str = len(s)
    len_pat = len(pat)
    i = 0
    j = 0
    while i < len_str and j < len_pat:
        if j == -1 or s[i] == pat[j]:
            i += 1
            j += 1
        else:
            j = next_list[j]

    if j == len_pat:
        return i - len_pat
    else:
        return -1


K = int(input())
A = [int(_) for _ in input().strip().split()]
B = [int(_) for _ in input().strip().split()]
N = int(input())
C = [int(_) for _ in input().strip().split()]
D = [int(_) for _ in input().strip().split()]

pattern = list(zip(A, B))
string = list(zip(C, D))
idx = kmp(string, pattern)

print(idx + 1)
