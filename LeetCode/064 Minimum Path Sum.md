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
