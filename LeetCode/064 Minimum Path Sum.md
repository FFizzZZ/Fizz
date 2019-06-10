```
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        d = {}
        def move(i, j):
            if (i, j) in d: return d[(i, j)]
            if i == m-1 and j == n-1:
                return grid[-1][-1]
            else:
                if i + 1 < m and j + 1 < n:
                    ans = grid[i][j] + min(move(i+1, j), move(i, j+1))
                if i == m - 1:
                    ans = grid[i][j] + move(i, j+1)
                if j == n - 1:
                    ans = grid[i][j] + move(i+1, j)
                d[(i, j)] = ans
                return ans
        return move(0, 0)
```

## dynamic programming
```
class Solution:
    def minPathSum(self, grid):
        m = len(grid)
        n = len(grid[0])
        for i in range(1, n):
            grid[0][i] += grid[0][i-1]
        for i in range(1, m):
            grid[i][0] += grid[i-1][0]
        for i in range(1, m):
            for j in range(1, n):
                grid[i][j] += min(grid[i-1][j], grid[i][j-1])
        return grid[-1][-1]
```
