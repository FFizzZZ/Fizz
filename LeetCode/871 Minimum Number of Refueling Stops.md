```
class Solution(object):
    def minRefuelStops(self, target, startFuel, stations):
        cur = startFuel
        pq = []
        n = len(stations)
        
        index = 0
        while index < n and stations[index][0] <= cur:
            heapq.heappush(pq, -stations[index][1])
            index += 1
        
        cnt = 0
        while pq and cur < target:
            cur -= heapq.heappop(pq)
            cnt += 1
            while index < n and stations[index][0] <= cur:
                heapq.heappush(pq, -stations[index][1])
                index += 1
        
        if cur < target:
            return -1
        else:
            return cnt
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
