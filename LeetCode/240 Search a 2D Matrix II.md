```
class Solution:
    def searchMatrix(self, matrix, target):
        if not matrix: return False
        m, n = len(matrix), len(matrix[0])
        i, j = m - 1, 0
        while i > -1 and j < n:
            val = matrix[i][j]
            if val == target:
                return True
            elif val < target:
                j += 1
            else:
                i -= 1
        return False
```
