class UnionFind:
    def __init__(self):
        self.parent = dict()
    
    def find(self, key):
        if key not in self.parent:
            self.parent[key] = key
            return key
        if key == self.parent[key]:
            return key
        self.parent[key] = self.find(self.parent[key]) # 路径压缩
        return self.parent[key]
    
    def union(self, key1, key2):
        '''
        把两个集合合并成一个
        '''
        self.parent[self.find(key1)] = self.find(key2)

class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        uf = UnionFind()

        for e in equations:

            if e[1] == '=':
                a = e[0]
                b = e[3]
                uf.union(a, b)

        for e in equations:
            if e[1] == '!':
                a = e[0]
                b = e[3]
                if uf.find(a) == uf.find(b):
                    return False
        
        return True