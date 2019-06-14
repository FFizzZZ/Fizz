```
class Solution(object):
    def setZeroes(self, matrix):
        r, c = len(matrix), len(matrix[0])
        rows, cols = set(), set()
        
        for i in range(r):
            for j in range(c):
                if matrix[i][j] == 0:
                    rows.add(i)
                    cols.add(j)
        for i in range(r):
            for j in range(c):
                if i in rows or j in cols:
                    matrix[i][j] = 0
```
## 用第一行，第一列标记
```
class Solution(object):
    def setZeroes(self, matrix):
        is_col = False
        R = len(matrix)
        C = len(matrix[0])
        for i in range(R):
            if matrix[i][0] == 0:
                is_col = True
            for j in range(1, C):
                if matrix[i][j]  == 0:
                    matrix[0][j] = 0
                    matrix[i][0] = 0
                    
        for i in range(1, R):
            for j in range(1, C):
                if not matrix[i][0] or not matrix[0][j]:
                    matrix[i][j] = 0

        if matrix[0][0] == 0:
            for j in range(C):
                matrix[0][j] = 0

        if is_col:
            for i in range(R):
                matrix[i][0] = 0
```
```
class Solution(object):
    def setZeroes(self, matrix):
        r, c = len(matrix), len(matrix[0])
        flag = 0
        for i in range(r):
            if matrix[i][0] == 0:
                flag = 1
            for j in range(1, c):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        for i in range(r-1, -1, -1):
            for j in range(c-1, 0, -1):
                if not matrix[i][0] or not matrix[0][j]:
                    matrix[i][j] = 0
            if flag: matrix[i][0] = 0
```
