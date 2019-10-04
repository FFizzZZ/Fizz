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
class Solution(object):
    def minFallingPathSum(self, A):
        n = len(A[0])
        for row in range(len(A) - 1, 0, -1):
            tmp = A[row]
            for i in range(n):
                A[row - 1][i] += min(tmp[max(0, i - 1) : min(n, i + 2)])
        return min(A[0])
```
