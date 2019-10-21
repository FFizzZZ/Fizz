## Dijkstra Algorithm

https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

a.初始时，S只包含源点，即S＝{v}，v的距离为0。U包含除v外的其他顶点，即:U={其余顶点}，若v与U中顶点u有边，则<u,v>正常有权值，若u不是v的出边邻接点，则<u,v>权值为∞。

b.从U中选取一个距离v最小的顶点k，把k，加入S中（该选定的距离就是v到k的最短路径长度）。

c.以k为新考虑的中间点，修改U中各顶点的距离；若从源点v到顶点u的距离（经过顶点k）比原来距离（不经过顶点k）短，则修改顶点u的距离值，修改后的距离值的顶点k的距离加上边上的权。

d.重复步骤b和c直到所有顶点都包含在S中。

![](https://github.com/FFizzZZ/Fizz/blob/master/Algorithm/Pictures/Dijkstra.png)
```
MAX_value = 999999
def dijkstra(graph, s):
    if graph is None:
        return None
    dist = [x for x in graph[s]]
    S = set()
    Q = set(i for i in range(len(graph)))
    while Q:
        u_dist, u = min([(d, v) for v, d in enumerate(dist) if v in Q])
        S.add(u)
        Q.discard(u)
        for v, d in enumerate(graph[u]):
            if 0 < d < MAX_value:
                if dist[v] > dist[u]+d:
                    dist[v] = dist[u]+d
    return dist
if __name__ == '__main__':
    graph_list = [ [0, 9, MAX_value, MAX_value, MAX_value, 14,15,MAX_value],
                    [9, 0, 24, MAX_value, MAX_value, MAX_value,MAX_value,MAX_value],
                    [MAX_value, 24, 0, 6, 2, 18,MAX_value,19],
                    [MAX_value, MAX_value, 6, 0, 11,MAX_value,MAX_value, 6],
                    [MAX_value,MAX_value, 2, 11, 0, 30,20, 16],
                    [14,MAX_value,18,MAX_value,30,0,5,MAX_value],
                    [15,MAX_value,MAX_value,MAX_value,20,5,0,44],
                    [MAX_value,MAX_value,19,6,16,MAX_value,44,0]]
    distance = dijkstra(graph_list, 0)
    print(distance)
```

#### Heap
```
ans = [0] * len(graph_list)
heap = [(0, 0)]
visited = set()
while heap:
    dist, cur = heapq.heappop(heap)
    if cur in visited: continue
    visited.add(cur)
    ans[cur] = dist
    for nxt, val in enumerate(graph_list[cur]):
        if nxt not in visited:
            heapq.heappush(heap, (dist + val, nxt))
print(ans)
```

## Bellman-Ford Algorithm

https://zh.wikipedia.org/wiki/%E8%B4%9D%E5%B0%94%E6%9B%BC-%E7%A6%8F%E7%89%B9%E7%AE%97%E6%B3%95
