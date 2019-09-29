```
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        points.sort(key = lambda x: x[0] ** 2 + x[1] ** 2)
        return points[:K]
```

```
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        heap = []
        for i in range(K):
            x, y = points[i]
            heap.append((- x ** 2 - y ** 2, x, y))
        heapq.heapify(heap)
        for i in range(K, len(points)):
            x, y = points[i]
            heapq.heappushpop(heap, (- x ** 2 - y ** 2, x, y))
        return [[x, y] for dist, x, y in heap]
```

## Leetcode
```
class Solution:
    def kClosest(self, points, K):
        return heapq.nsmallest(K, points, lambda x: x[0] ** 2 + x[1] ** 2)
```
