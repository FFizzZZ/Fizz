## Leetcode
#### Dijkstra Algorithm (Fastest)
```
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        graph = collections.defaultdict(list)
        for start, end, price in flights:
            graph[start].append([end, price])
        heap = [(0, src, 0)]
        visited = set()
        while heap:
            cost, cur, steps = heapq.heappop(heap)
            if steps > K + 1:
                continue
            if cur == dst:
                return cost
            visited.add(cur)
            for nxt, price in graph[cur]:
                if nxt not in visited:
                    heapq.heappush(heap, (cost + price, nxt, steps + 1))
        return -1
```
        
#### Bellman-Ford Algorithm       
```
class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        dist = [float("inf")] * n
        dist[src] = 0
        for _ in range(K + 1):
            new = dist[:]
            for start, end, price in flights:
                new[end] = min(new[end], dist[start] + price)
            dist = new
        return -1 if dist[dst] == float("inf") else dist[dst]
```
        
        

