```
import queue
class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        cur = startFuel
        stations.sort()
        n = len(stations)
        
        q = queue.PriorityQueue()
        index = 0
        while index <= n - 1 and stations[index][0] <= cur:
            q.put(-stations[index][1])
            index += 1
        
        cnt = 0
        while cur < target and q.qsize():
            cur -= q.get()
            while index <= n - 1 and stations[index][0] <= cur:
                q.put(-stations[index][1])
                index += 1
            cnt += 1
        if cur >= target:
            return cnt
        else:
            return -1
```


## Leetcode
```
class Solution(object):
    def minRefuelStops(self, target, tank, stations):
        cnt = 0
        pq = []
        pre = 0
        stations.append((target, float('inf')))
        for loc, fuel in stations:
            tank -= loc - pre
            while pq and tank < 0:
                tank += -heapq.heappop(pq)
                cnt += 1
            if tank < 0: return -1
            heapq.heappush(pq, -fuel)
            pre = loc
        return cnt
```
