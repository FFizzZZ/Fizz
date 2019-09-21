```
class Solution:
    def distanceBetweenBusStops(self, distance: List[int], start: int, destination: int) -> int:
        total = sum(distance)
        if start < destination:
            cur = sum(distance[start:destination])
        else:
            cur = sum(distance[destination:start])
        return min(cur, total - cur)
```
