from typing import List


class UnionFind:
    def __init__(self):
        self.parent = dict()

    def find(self, key):
        if key not in self.parent:
            self.parent[key] = key
            return key
        if key == self.parent[key]:
            return key
        self.parent[key] = self.find(self.parent[key])  # 路径压缩
        return self.parent[key]

    def union(self, key1, key2):
        '''
        把两个集合合并成一个
        '''
        p1 = self.find(key1)
        p2 = self.find(key2)
        if p1 < p2:
            self.parent[p2] = p1
        else:
            self.parent[p1] = p2


class Solution:
    def trulyMostPopular(self, names: List[str],
                         synonyms: List[str]) -> List[str]:
        uf = UnionFind()
        for name_pair in synonyms:
            name1 = name_pair.split(',')[0][1:]
            name2 = name_pair.split(',')[1][:-1]
            uf.union(name1, name2)

        sum_dict = dict()

        for name_cnt in names:
            name = name_cnt.split('(')[0]
            tmp_cnt = int(name_cnt.split('(')[1].split(')')[0])

            s = uf.find(name)

            tmp_sum = sum_dict.get(s, 0)
            tmp_sum += tmp_cnt

            sum_dict[s] = tmp_sum

        res = ['{}({})'.format(k, v) for k, v in sum_dict.items()]
        return res
