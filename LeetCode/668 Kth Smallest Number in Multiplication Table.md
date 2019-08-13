## Leetcode
#### Hea TLE!
```
class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        heap = [(i, i) for i in range(1, m + 1)]
        heapq.heapify(heap)
        for _ in range(k):
            val, root = heapq.heappop(heap)
            nxt = val + root
            if nxt <= root * n:
                heapq.heappush(heap, (nxt, root))
        return val
```
