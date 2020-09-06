def fast_pow(a, b, c):
    '''
    pow(a, b) % c
    '''
    ans = 1
    base = a % c

    if b == 0:
        return 1 % c

    while b:
        # 判断奇偶
        if b & 1:
            ans = (ans * base) % c
        b = b >> 1
        base = (base * base) % c

    return ans


def fast_pow_py(a, b):
    '''
    python的int不会溢出, 因此可以不mod
    pow(a, b)
    '''
    ans = 1
    base = a

    if b == 0:
        return 1

    while b:
        # 判断奇偶
        if b & 1:
            ans = (ans * base)
        b = b >> 1
        base = (base * base)

    return ans
