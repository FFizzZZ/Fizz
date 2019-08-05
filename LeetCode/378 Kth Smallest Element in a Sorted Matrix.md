## Leetcode

#### An idea similar to 23 merging K sorted linked list
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

#### Binary Search
```
class Solution(object):
    def kthSmallest(self, matrix, k):
        l, r = matrix[0][0], matrix[-1][-1]
        while l < r:
            mid = (l + r) // 2
            if sum(bisect.bisect_right(row, mid) for row in matrix) < k:
                l = mid + 1
            else:
                r = mid
        return l
```
