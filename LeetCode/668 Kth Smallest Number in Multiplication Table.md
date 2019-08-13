## Leetcode
#### Heap TLE!
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

#### Binary Search
```
class Solution:
    def findKthNumber(self, m: int, n: int, k: int) -> int:
        l, r = 0, m * n
        while l < r:
            mid = (l + r) // 2
            if self.count(mid, m, n) < k:
                l = mid + 1
            else:
                r = mid
        return l
    
    def count(self, x, m, n):
        cnt = 0
        for i in range(1, m + 1):
            cnt += min(x // i, n)
        return cnt
```
