```
class Solution(object):
    def findOrder(self, n, p):
        ans = []
        degree = [0] * n
        graph = [[] for _ in range(n)]
        for x, y in p:
            graph[y].append(x)
            degree[x] += 1
        queue = []
        for i in range(n):
            if degree[i] == 0:
                queue.append(i)
        while queue:
            cur = queue.pop()
            ans.append(cur)
            for i in graph[cur]:
                degree[i] -= 1
                if degree[i] == 0:
                    queue.append(i)
        return ans if len(ans) == n else []
```
## Leetcode
```
from collections import defaultdict
class Solution:
    def findOrder(self, numCourses, prerequisites):
        adj_list = defaultdict(list)
        indegree = {}
        for dest, src in prerequisites:
            adj_list[src].append(dest)
            indegree[dest] = indegree.get(dest, 0) + 1
        zero_indegree_queue = [k for k in range(numCourses) if k not in indegree]
        topological_sorted_order = []
        while zero_indegree_queue:
            vertex = zero_indegree_queue.pop(0)
            topological_sorted_order.append(vertex)
            if vertex in adj_list:
                for neighbor in adj_list[vertex]:
                    indegree[neighbor] -= 1
                    if indegree[neighbor] == 0:
                        zero_indegree_queue.append(neighbor)
        return topological_sorted_order if len(topological_sorted_order) == numCourses else []
```

```
from collections import defaultdict
class Solution:
    WHITE = 1
    GRAY = 2
    BLACK = 3
    def findOrder(self, numCourses, prerequisites):
        adj_list = defaultdict(list)
        for dest, src in prerequisites:
            adj_list[src].append(dest)
        topological_sorted_order = []
        is_possible = True
        color = {k: Solution.WHITE for k in range(numCourses)}
        def dfs(node):
            nonlocal is_possible
            if not is_possible:
                return
            color[node] = Solution.GRAY

            if node in adj_list:
                for neighbor in adj_list[node]:
                    if color[neighbor] == Solution.WHITE:
                        dfs(neighbor)
                    elif color[neighbor] == Solution.GRAY:
                        is_possible = False

            color[node] = Solution.BLACK
            topological_sorted_order.append(node)

        for vertex in range(numCourses):
            if color[vertex] == Solution.WHITE:
                dfs(vertex)

        return topological_sorted_order[::-1] if is_possible else []
```
