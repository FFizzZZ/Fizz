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
def findCheapestPrice(self, n, flights, src, dst, K):
    costs = [float('inf')] * n
    costs[src] = 0

    for _ in range(K+1):
        copy = costs[:]
        for s, d, w in flights:
            copy[d] = min(copy[d], costs[s] + w)
        costs = copy

    return -1 if costs[dst] == float('inf') else costs[dst]
```
        
        

