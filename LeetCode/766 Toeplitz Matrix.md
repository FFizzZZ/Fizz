## Leetcode

#### Group by Category
```
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        d = dict()
        for r, row in enumerate(matrix):
            for c, val in enumerate(row):
                if r - c not in d:
                    d[r - c] = val
                elif d[r - c] != val:
                    return False
        return True
```

#### Compare with Top-Left Neighbor
```
class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        return all(r == 0 or c == 0 or matrix[r - 1][c - 1] == val
                  for r, row in enumerate(matrix)
                  for c, val in enumerate(row))
```
