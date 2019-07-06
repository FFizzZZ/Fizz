## Leetcode
```
class Solution(object):
    def numIslands(self, grid):
        if not grid: return 0
        n, m = len(grid), len(grid[0])
        count = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
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
