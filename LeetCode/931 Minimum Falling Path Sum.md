```
class Solution:
    def minFallingPathSum(self, A: List[List[int]]) -> int:
        memo = dict()
        return min(self.dfs(0, col, A, memo) for col in range(len(A[0])))
    def dfs(self, row, col, A, memo):
        if (row, col) in memo:
            return memo[row, col]
        if row == len(A): return 0
        val = A[row][col]
        nxt = [col + x for x in range(-1, 2) if 0 <= col + x < len(A[0])]
        ans = val + min(self.dfs(row + 1, c, A, memo) for c in nxt)
        memo[row, col] = ans
        return ans
```

## Leetcode
#### Dynamic Programming
```
class Solution:
    def minFallingPathSum(self, A: List[List[int]]) -> int:
        row, col = len(A), len(A[0])
        for i in range(1, row):
            for j in range(col):
                if j == 0:
                    A[i][j] += min(A[i - 1][j], A[i - 1][j + 1])
                elif j == col - 1:
                    A[i][j] += min(A[i - 1][j - 1], A[i - 1][j])
                else:
                    A[i][j] += min(A[i - 1][j - 1], A[i - 1][j], A[i - 1][j + 1])
        return min(A[-1])
```
