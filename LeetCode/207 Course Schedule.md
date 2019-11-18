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
        
        
        
        
        
        
     








    
