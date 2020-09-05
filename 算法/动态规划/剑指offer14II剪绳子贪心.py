#
'''
n = n1 + n2

已知 
n1 * n2 >= n, (n>=4, n1>1, n2>1)

且
n=4, 2*2 = 2+2
n=5, 2*3 > 2+3

按照这个套路, 所有n>=4, 划分的收益大于不划分的收益, 最后肯定会分成2/3的子段

那2 3哪个好呢?

推论: 尽可能多的3

即 3(n-3) >= 2(n-2)
即 n >= 5

'''
'''
2 <= n <= 1000 

大数mod

剪成m段 , m>1

不能不剪

但是,有些情况, 不剪比剪的收益大

x = (x/2) * (x/2)  得 x = 4, 即 x>=4时, 剪开的收益大于不剪的

x=2,3时 不剪的收益更大
'''

MOD = int(1e9 + 7)  # 不加int, 那就是float


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


class Solution:
    def cuttingRope(self, n: int) -> int:

        if n < 2:
            return 0
        if n == 2:
            return 1
        if n == 3:
            return 2
        if n == 4:
            return 4

        shang = n // 3
        yushu = n % 3

        # 考虑 溢出
        # 快速幂

        if yushu == 1:
            shang = (n - 4) // 3

            ans = fast_pow(3, shang, MOD) * 4 % MOD

        elif yushu == 0:
            ans = fast_pow(3, shang, MOD)
        else:
            ans = fast_pow(3, shang, MOD) * 2 % MOD
        return ans