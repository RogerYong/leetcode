from typing import List


class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        if numRows < 1:
            return []
        
        for i in range(numRows):
            if i == 0:
                res.append([1])
            elif i == 1:
                res.append([1,1])
            else:
                cur_row = []
                cur_row.append(1)
                for j in range(i-1):
                    cur_row.append( res[i-1][j] + res[i-1][j+1])
                cur_row.append(1)
                res.append(cur_row)
        return res
    

if __name__ == "__main__":
    cases = [
       1,2,3,4,5
    ]
    s = Solution()
    for n in cases:
        res =s.generate(n)
        print(n,res)