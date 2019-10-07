##### FASTEST
```
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        island_ = 0
        m, n = len(grid), len(grid[0])
        for i in range(m):
            for j in range(n):
                if grid[i][j] == 1:
                    shape = self.dfs(grid, i, j)
                    island_ = max(shape, island_)
        return island_
    def dfs(self, Grid, x, y):
            m, n = len(Grid), len(Grid[0])
            Grid[x][y] = 0
            area = 1
            if x - 1 >= 0 and Grid[x - 1][y] == 1:
                area += self.dfs(Grid, x-1, y) 
            if x + 1 < m and Grid[x + 1][y] == 1:
                area += self.dfs(Grid, x + 1, y)
            if y - 1 >= 0 and Grid[x][y - 1] == 1:
                area += self.dfs(Grid, x, y - 1)
            if y + 1 < n and Grid[x][y + 1] == 1:
                area += self.dfs(Grid, x, y + 1)
            return area
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













