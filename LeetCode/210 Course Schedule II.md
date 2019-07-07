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
