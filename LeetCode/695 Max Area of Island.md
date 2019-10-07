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

## Leetcode
#### Iterative
```
class Solution(object):
    def maxAreaOfIsland(self, grid):
        seen = set()
        ans = 0
        for r0, row in enumerate(grid):
            for c0, val in enumerate(row):
                if val and (r0, c0) not in seen:
                    shape = 0
                    stack = [(r0, c0)]
                    seen.add((r0, c0))
                    while stack:
                        r, c = stack.pop()
                        shape += 1
                        for nr, nc in ((r-1, c), (r+1, c), (r, c-1), (r, c+1)):
                            if (0 <= nr < len(grid) and 0 <= nc < len(grid[0])
                                    and grid[nr][nc] and (nr, nc) not in seen):
                                stack.append((nr, nc))
                                seen.add((nr, nc))
                    ans = max(ans, shape)
        return ans
```













