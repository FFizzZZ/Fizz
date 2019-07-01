```
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        triangle = [1]
        for row_num in range(rowIndex + 1):
            row = [None for _ in range(row_num+1)]
            row[0], row[-1] = 1, 1
            for j in range(1, len(row)-1):
                row[j] = triangle[j-1] + triangle[j]
            triangle = row
        return triangle
```

## Leetcode
```
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans = [0] * (rowIndex + 1)
        ans[0] = 1
        for i in range(1, rowIndex + 1):
            for j in range(i, 0, -1):
                ans[j] += ans[j - 1]
        return ans
```
