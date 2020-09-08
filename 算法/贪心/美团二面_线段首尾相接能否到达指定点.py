'''
美团二面

给定正整型数组 array , 保存的是线段的长度

给定起点(0,0), 目标(x,y)

问, 从array中依次取出线段,首尾相接,

最少几个线段能到达(x, y)

'''

import math


def solve(array, x, y):
    '''
    若干线段连接, 形成的区域是圆环

    每次得到一个圆环后, 判断sqrt(x*x+y*y)是否在圆环内即可
    '''
    radius_max = [0] * len(array)
    radius_min = [0] * len(array)

    radius = math.sqrt(x * x + y * y)

    for i in range(len(array)):
        if i == 0:
            radius_max[i] = array[i]
            radius_min[i] = array[i]
        else:
            radius_max[i] = radius_max[i - 1] + array[i]
            if array[i] <= radius_min[i - 1]:
                radius_min[i] = radius_min[i - 1] - array[i]
            elif array[i] >= radius_max[i - 1]:
                radius_min[i] = array[i] - radius_max[i - 1]
            else:
                radius_min[i] = 0
        if radius_max[i] >= radius and radius_min[i] <= radius:
            return i + 1
    return None
