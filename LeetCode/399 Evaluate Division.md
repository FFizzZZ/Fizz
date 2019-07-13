## Leetcode
```
class Solution(object):
    def calcEquation(self, equations, values, queries):
        graph = collections.defaultdict(list)
        for nodes, val in zip(equations, values):
            f, t = nodes
            self.add_edge(f, t, val, graph)
        return [self.find(q, graph) for q in queries]
    def add_edge(self, f, t, val, graph):
        graph[f].append((t, val))
        graph[t].append((f, 1 / val))
    def find(self, query, graph):
        start, end = query
        if start not in graph or end not in graph:
            return -1.0
        stack = [(start, 1.0)]
        visited = set()
        while stack:
            temp, value = stack.pop()
            if temp == end:
                self.add_edge(start, end, value, graph)
                return value
            visited.add(temp)
            for node, val in graph[temp]:
                if node not in visited:
                    stack.append((node, value * val))
        return -1.0
```

```
class Solution(object):
    def calcEquation(self, equations, values, queries):
        graph = collections.defaultdict(dict)
        for (start, end), val in zip(equations, values):
            graph[start][start] = graph[end][end] = 1.0
            graph[start][end] = val
            graph[end][start] = 1 / val
        for i, j, k in itertools.permutations(graph, 3):
            if j in graph[i] and k in graph[j]:
                graph[i][k] = graph[i][j] * graph[j][k]
        return [graph[start].get(end, -1.0) for start, end in queries]
```
        
        
        
        
        





