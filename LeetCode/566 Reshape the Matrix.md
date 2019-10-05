```
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        m, n = len(nums), len(nums[0])
        N = m * n
        if N != r * c: return nums
        matrix = [[0] * c for _ in range(r)]
        tmp = []
        for i in range(m):
            tmp.extend(nums[i])
        for i in range(r):
            matrix[i] = tmp[c * i: c * i + c]
        return matrix
```

## Leetcode
```
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        m, n = len(nums), len(nums[0])
        if m * n != r * c: return nums
        matrix = [[0] * c for _ in range(r)]
        row = col = 0
        for i in range(r):
            for j in range(c):
                matrix[i][j] = nums[row][col]
                col += 1
                if col == n:
                    row += 1
                    col = 0
        return matrix
```

```
class Solution:
    def matrixReshape(self, nums: List[List[int]], r: int, c: int) -> List[List[int]]:
        m, n = len(nums), len(nums[0])
        if m * n != r * c: return nums
        matrix = [[0] * c for _ in range(r)]
        cnt = 0
        for i in range(m):
            for j in range(n):
                row, col = divmod(cnt, c)
                matrix[row][col] = nums[i][j]
                cnt += 1
        return matrix
```
