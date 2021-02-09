import math


##################
# 01背包
#############
def zero_one_backpack(n, capacity, costs, weights):
    '''
    01背包+最大收益

    n: 物品数
    capacity: 背包总容量
    costs: N个物品的占据的空间
    weights: N个物品的收益
    '''
    dp = [0] * (capacity + 1)  # 初始化dp矩阵, i从0开始

    for i in range(n):  # 0到n-1
        for j in range(capacity, costs[i] - 1, -1):
            dp[j] = max(dp[j], dp[j - costs[i]] + weights[i])

    return dp[capacity]


def zero_one_backpack_opt(n, capacity, costs, weights):
    '''
    01背包, 通过cost_sums以空间换时间, 获得常数优化

    n: 物品数
    capacity: 背包总容量
    costs: N个物品的占据的空间
    weights: N个物品的收益
    cost_sums[i]: 表示costs[i:]的和
    '''
    dp = [0] * (capacity + 1)  # 初始化dp矩阵, i从0开始

    ####
    # 以空间换时间, 常数优化
    cost_sums = [0] * n
    cost_sums[n - 1] = costs[n - 1]

    for i in range(n - 2, -1, -1):
        cost_sums[i] = cost_sums[i + 1] + costs[i]
    ####

    for i in range(n):  # 0到n-1
        for j in range(capacity,
                       max(capacity - cost_sums[i], costs[i]) - 1, -1):
            dp[j] = max(dp[j], dp[j - costs[i]] + weights[i])

    return dp[capacity]


def zero_one_backpack_full(n, capacity, costs):
    '''
    能否装满背包

    n: 物品数
    capacity: 背包总容量
    costs: N个物品的占据的空间
    '''
    dp = [-math.inf] * (capacity + 1)  # 初始化dp矩阵
    dp[0] = 0  # 容量0

    for i in range(n):  # 0到n-1
        for j in range(capacity, costs[i] - 1, -1):
            dp[j] = max(dp[j], dp[j - costs[i]])

    return dp[capacity]


def zero_one_backpack_full_opt(n, capacity, costs):
    '''
    能否装满背包

    n: 物品数
    capacity: 背包总容量
    costs: N个物品的占据的空间
    cost_sums[i]: 表示costs[i:]的和
    '''
    dp = [-math.inf] * (capacity + 1)  # 初始化dp矩阵
    dp[0] = 0  # 容量0

    ####
    # 以空间换时间, 常数优化
    cost_sums = [0] * n
    cost_sums[n - 1] = costs[n - 1]

    for i in range(n - 2, -1, -1):
        cost_sums[i] = cost_sums[i + 1] + costs[i]
    ####

    for i in range(n):  # 0到n-1
        for j in range(capacity,
                       max(capacity - cost_sums[i], costs[i]) - 1, -1):
            dp[j] = max(dp[j], dp[j - costs[i]])

    return dp[capacity]


def zero_one_backpack_full_max_weights(n, capacity, costs, weights):
    '''
    装满背包且收益最大

    n: 物品数
    capacity: 背包总容量
    costs: N个物品的占据的空间
    weights: N个物品的收益
    cost_sums[i]: 表示costs[i:]的和
    '''
    dp = [-math.inf] * (capacity + 1)  # 初始化dp矩阵
    dp[0] = 0  # 容量0

    ####
    # 以空间换时间, 常数优化
    cost_sums = [0] * n
    cost_sums[n - 1] = costs[n - 1]

    for i in range(n - 2, -1, -1):
        cost_sums[i] = cost_sums[i + 1] + costs[i]
    ####

    for i in range(n):  # 0到n-1
        for j in range(capacity,
                       max(capacity - cost_sums[i], costs[i]) - 1, -1):
            dp[j] = max(dp[j], dp[j - costs[i]] + weights[i])

    return dp[capacity]


#############################
# 完全背包
##############################
def complete_backpack(n, capacity, costs, weights):
    '''
    完全背包+最大收益

    n: 物品数
    capacity: 背包总容量
    costs: N个物品的占据的空间
    '''
    dp = [0] * (capacity + 1)  # 初始化dp矩阵

    for i in range(n):  # 0到n-1
        for j in range(costs[i], capacity + 1):  # 完全背包从小到大
            dp[j] = max(dp[j], dp[j - costs[i]] + weights[i])

    return dp[capacity]


def complete_backpack_num_combinations(capacity, costs):
    '''
    完全背包+组合数

    n: 物品数
    capacity: 背包总容量
    costs: N个物品的占据的空间
    '''
    n = len(costs)
    dp = [0] * (capacity + 1)  # 初始化dp矩阵
    dp[0] = 1  # 组成容量0的情况, 设为1

    for i in range(n):  # 0到n-1
        for j in range(costs[i], capacity + 1):  # 完全背包从小到大
            dp[j] = dp[j] + dp[j - costs[i]]

    return dp[capacity]


################
# 多重背包
################
def multiple_pack(n, capacity, costs, weights, multi):
    '''
    多重背包+最大收益

    转01背包+最大收益

    容易理解的方法

    n: 物品数
    capacity: 背包总容量
    costs: N个物品的占据的空间
    weights: N个物品的收益
    multi: 每件物品最多multi[i]件
    '''

    # 构造 costs 和weights
    costs_multi = []
    weights_multi = []

    for i in range(n):
        # k
        k = int(math.log2(multi[i] + 1))

        prefix = [2**i for i in range(k - 1)]

        if multi[i] + 1 - 2**k > 0:
            prefix.append(multi[i] + 1 - 2**k)

        costs_multi.extend([costs[i] * pre for pre in prefix])
        weights_multi.extend([weights[i] * pre for pre in prefix])

    # 转换01背包
    n_multi = len(costs_multi)

    return zero_one_backpack(n_multi, capacity, costs_multi, weights_multi)


def multiple_pack_opt(n, capacity, costs, weights, multi):
    '''
    多重背包+最大收益

    转完全背包/01背包+最大收益

    n: 物品数
    capacity: 背包总容量
    costs: N个物品的占据的空间
    weights: N个物品的收益
    multi: 每件物品最多multi[i]件
    '''
    dp = [0] * (capacity + 1)

    for i in range(n):
        if costs[i] * multi[i] >= capacity:
            # 完全背包
            for j in range(costs[i], capacity + 1):  # 完全背包从小到大
                dp[j] = max(dp[j], dp[j - costs[i]] + weights[i])
        else:
            # 01背包
            m = multi[i]
            k = 1
            while k < m:
                for j in range(capacity, k * costs[i] - 1, -1):
                    dp[j] = max(dp[j], dp[j - k * costs[i]] + k * weights[i])

                m -= k
                k *= 2
            for j in range(capacity, m * costs[i] - 1, -1):
                dp[j] = max(dp[j], dp[j - m * costs[i]] + m * weights[i])
