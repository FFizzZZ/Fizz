## Leetcode
```
import heapq
class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:       
        if not heightMap: return 0
        q = []
        m, n = len(heightMap), len(heightMap[0])
        for i in range(m): 
            heapq.heappush(q, (heightMap[i][0], i, 0))
            heapq.heappush(q, (heightMap[i][n-1], i, n-1))
            heightMap[i][0] = -1
            heightMap[i][n-1] = -1
        for j in range(1,n-1):
            heapq.heappush(q, (heightMap[0][j], 0, j) )
            heapq.heappush(q, (heightMap[m-1][j], m-1, j) )
            heightMap[0][j] = -1
            heightMap[m-1][j] = -1
        min_ = 0
        total = 0
        while q:
            h, i, j = heapq.heappop(q)
            if h < min_ : 
                total += min_ - h
            else:
                min_ = h
            for di, dj in ((0, 1), (1, 0), (-1, 0), (0, -1)):
                x, y = i + di, j + dj
                if 0 <= x < m and 0 <= y < n and heightMap[x][y] >= 0:
                    heapq.heappush(q, (heightMap[x][y], x, y))
                    heightMap[x][y] = -1
        return total
```
