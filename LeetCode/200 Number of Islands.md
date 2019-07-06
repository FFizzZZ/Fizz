## Leetcode
```
class Solution(object):
    def numIslands(self, grid):
        if not grid or not grid[0]:
            return 0            
        islands = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    self.explore(grid, i, j)
                    islands += 1
        return islands       
    def explore(self, g, x, y):
        g[x][y] = "X"       
        if x - 1 >= 0 and g[x-1][y] == "1":
            self.explore(g, x - 1, y)
        if y - 1 >= 0 and g[x][y - 1] == "1":
            self.explore(g, x, y - 1)
        if x + 1 < len(g) and g[x+1][y] == "1":
            self.explore(g, x + 1, y)
        if y + 1 < len(g[0]) and g[x][y + 1] == "1":
            self.explore(g, x, y + 1)
```
#### UnionFind
```
class Solution(object):
    def numIslands(self, grid):
        if not grid: return 0
        uf = UnionFind(grid)
        rows, cols = len(grid), len(grid[0])
        distance = [[1, 0], [0, 1]]
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == '1':
                    for d in distance:
                        x = i + d[0]
                        y = j + d[1]
                        if 0 <= x < rows and 0 <= y < cols and grid[x][y] == '1':
                            id1 = i * cols + j
                            id2 = x * cols + y
                            uf.union(id1, id2)
        return uf.count
class UnionFind:
    def __init__(self, grid):
        m, n = len(grid), len(grid[0])
        self.count = 0
        self.father = [None] * m * n
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '1':
                    id = i * n + j
                    self.father[id] = id
                    self.count += 1
    def union(self, x, y):
        rootx = self.find(x)
        rooty = self.find(y)
        if rootx != rooty:
            self.father[rootx] = rooty
            self.count -= 1
    def find(self, x):
        while self.father[x] != x:
            x = self.father[x]
        return x
```
