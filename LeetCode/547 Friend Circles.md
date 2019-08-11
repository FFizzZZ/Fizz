## Leetcode
```
class Solution:
    def findCircleNum(self, M: List[List[int]]) -> int:
        visited = set()
        cnt = 0
        for i in range(len(M)):
            if i not in visited:
                visited.add(i)
                self.f(i, M, visited)
                cnt += 1
        return cnt
        
    def f(self, i, M, visited):
        for j in range(len(M)):
            if M[i][j] == 1 and j not in visited:
                visited.add(j)
                self.f(j, M, visited)
```
