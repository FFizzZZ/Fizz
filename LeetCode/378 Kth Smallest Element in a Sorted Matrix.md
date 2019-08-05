```
import queue
class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        n = len(matrix)
        q = queue.PriorityQueue()
        for j in range(n):
            q.put([matrix[0][j], 0, j])
        for _ in range(k - 1):
            _, x, y = q.get()
            if x == n - 1: continue
            q.put([matrix[x + 1][y], x + 1, y])
        return q.get()[0]
```
