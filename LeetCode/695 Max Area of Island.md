```
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ans = 0
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    val = self.dfs(i, j, grid, m, n)
                    if val > ans: ans = val
        return ans
    
    def dfs(self, row, col, grid, m, n):
        ans = 1
        grid[row][col] = 0
        for x, y in [(row, col + 1), (row, col - 1), (row + 1, col), (row - 1, col)]:
            if 0 <= x < m and 0 <= y < n and grid[x][y] == 1:
                ans += self.dfs(x, y, grid, m, n)
        return ans
```
