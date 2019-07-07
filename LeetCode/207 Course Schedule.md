## Leetcode
#### Topological Sort
```
class Solution(object):
    def canFinish(self, n, p):
        matrix = [[] for _ in range(n)]
        degree = [0] * n
        for i in p:
            now, pre = i
            matrix[pre].append(now)
            degree[now] += 1
        queue = []
        for i in range(n):
            if degree[i] == 0: queue.append(i)
        while queue:
            cur = queue.pop()
            n -= 1
            for i in matrix[cur]:
                degree[i] -= 1
                if degree[i] == 0:
                    queue.append(i)
        return n == 0
```

```
class Solution(object):
  def canFinish(self, numCourses, prerequisites):
      graph = [[] for _ in xrange(numCourses)]
      visit = [0 for _ in xrange(numCourses)]
      for x, y in prerequisites:
          graph[x].append(y)
      def dfs(i):
          if visit[i] == -1:
              return False
          if visit[i] == 1:
              return True
          visit[i] = -1
          for j in graph[i]:
              if not dfs(j):
                  return False
          visit[i] = 1
          return True
      for i in xrange(numCourses):
          if not dfs(i):
              return False
      return True
```
        
        
        
        
        
        
     








    
