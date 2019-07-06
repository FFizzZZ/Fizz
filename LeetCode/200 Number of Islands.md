## Leetcode
```
class Solution(object):
    def numIslands(self, grid):
        if not grid: return 0
        n, m = len(grid), len(grid[0])
        count = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    self.f(grid, i, j)
                    count += 1
        return count
    def f(self, grid, i, j):
        if i < 0 or j < 0 or i == len(grid) or j == len(grid[0]) or grid[i][j] == '0':
            return
        grid[i][j] = '0'
        self.f(grid, i + 1, j)
        self.f(grid, i - 1, j)
        self.f(grid, i, j + 1)
        self.f(grid, i, j - 1)
```
