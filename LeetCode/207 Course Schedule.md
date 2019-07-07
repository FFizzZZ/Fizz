## Leetcode
```
class Solution(object):
    def canFinish(self, n, p):
        matrix = [[0] * n for _ in range(n)]
        indegree = [0] * n
        for i in range(len(p)):
            ready, pre = p[i]
            matrix[pre][ready] = 1
            indegree[ready] += 1
        count = 0
        queue = []
        for i in range(len(indegree)):
            if indegree[i] == 0: queue.append(i)
        while queue:
            cur = queue.pop(0)
            count += 1
            for i in range(n):
                if matrix[cur][i] != 0:
                    indegree[i] -= 1
                    if indegree[i] == 0:
                        queue.append(i)
        return n == count
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
        
        
        
        
        
        
     








    
