## Leetcode
#### Topological Sort
```
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        matrix = [[] for _ in range(numCourses)]
        degree = [0] * numCourses
        for cur, pre in prerequisites:
            matrix[pre].append(cur)
            degree[cur] += 1
        queue = []
        for i in range(numCourses):
            if degree[i] == 0:
                queue.append(i)
        while queue:
            cur = queue.pop()
            numCourses -= 1
            for nxt in matrix[cur]:
                degree[nxt] -= 1
                if degree[nxt] == 0:
                    queue.append(nxt)
        return numCourses == 0
```

```
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = [[] for _ in range(numCourses)]
        visited = [0] * numCourses
        for cur, pre in prerequisites:
            graph[cur].append(pre)
        def dfs(cur):
            if visited[cur] == -1:
                return False
            if visited[cur] == 1:
                return True
            visited[cur] = -1
            for pre in graph[cur]:
                if not dfs(pre):
                    return False
            visited[cur] = 1
            return True
        for cur in range(numCourses):
            if not dfs(cur):
                return False
        return True
```
