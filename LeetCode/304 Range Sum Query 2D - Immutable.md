```
class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        if not matrix: return 
        m, n = len(matrix), len(matrix[0])
        prefix = [[0] * (n + 1) for _ in range(m)]
        for i in range(m):
            row = prefix[i]
            for j in range(n):
                row[j + 1] = row[j] + matrix[i][j]
        self.prefix = prefix
                
    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        ans = 0
        for i in range(row1, row2 + 1):
            row = self.prefix[i]
            ans += row[col2 + 1] - row[col1]
        return ans
```
## Leetcode
```
class NumMatrix:
    def __init__(self, matrix: List[List[int]]):
        if not matrix: return None
        row, col = len(matrix), len(matrix[0])
        tmp = [[0] * (col + 1) for _ in range(row + 1)]
        for i in range(row):
            for j in range(col):
                tmp[i + 1][j + 1] = tmp[i][j + 1] + tmp[i + 1][j] + matrix[i][j] - tmp[i][j]
        self.tmp = tmp        

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return self.tmp[row2 + 1][col2 + 1] - self.tmp[row2 + 1][col1] - self.tmp[row1][col2 + 1] + self.tmp[row1][col1]
```
