```
class Solution:
    def swimInWater(self, grid):
        n = len(grid)
        heap = [(grid[0][0], 0, 0)]
        cnt = 0
        visited = set([(0, 0)])
        while True:
            t, x, y = heapq.heappop(heap)
            if t > cnt:
                cnt = t
            if x == y == n - 1:
                return cnt
            for nx, ny in [(x + 1, y), (x, y + 1), (x - 1, y), (x, y - 1)]:
                if 0 <= nx < n and 0 <= ny < n and (nx, ny) not in visited:
                    visited.add((nx, ny))
                    heapq.heappush(heap, (grid[nx][ny], nx, ny))
```
