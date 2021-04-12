def Multiply(a, b):
    """
    a,b are lists of 1000 elements with value ranges 0~9,
    and return another list of 2000 element equals a multiply b.
    """
    if not a or not b:
        return None
    # 去掉前导0
    a_idx = len(a) - 1
    while a_idx >= 0 and a[a_idx] == 0:
        a_idx -= 1
    b_idx = len(b) - 1
    while b_idx >= 0 and b[b_idx] == 0:
        b_idx -= 1

    c = [0] * 2000
    # 对应位置相乘
    for i in range(a_idx + 1):
        for j in range(b_idx + 1):
            c[i + j] += a[i] * b[j]
    # 进位
    carry = 0
    for i in range(a_idx + b_idx + 2):
        c[i] += carry
        carry = c[i] // 10
        c[i] = c[i] % 10

    return c
