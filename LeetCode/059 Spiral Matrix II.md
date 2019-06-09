```
class Solution:
    def generateMatrix(self, n):
        m = [[0] * n for _ in range(n)]
        d = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        x, y = 0, -1
        dx, dy = 0, 1
        path = {}
        count = 0
        for i in range(1, n ** 2 + 1):
            x += dx
            y += dy
            if x < 0 or x >= n or y < 0 or y >= n or (x, y) in path:
                x -= dx
                y -= dy
                count += 1
                dx, dy = d[count % 4]
                x += dx
                y += dy
            m[x][y] = i
            path[(x, y)] = 1
        return m
```
