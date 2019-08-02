```
class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix: return 0
        d = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        m, n = len(matrix), len(matrix[0])
        ans = 1
        for i in range(m):
            for j in range(n):
                tmp = self.f(i, j, matrix, d, m, n)
                if tmp > ans:
                    ans = tmp
        return ans
    def f(self, x, y, matrix, d, m, n):
        tmp = matrix[x][y]
        matrix[x][y] = None
        ans = 0
        for dx, dy in d:
            newx, newy = x + dx, y + dy
            if 0 <= newx < m and 0 <= newy < n:
                val = matrix[newx][newy]
                if val and val > tmp:
                    ans = max(ans, self.f(newx, newy, matrix, d, m, n))
        matrix[x][y] = tmp
        return ans + 1
```
