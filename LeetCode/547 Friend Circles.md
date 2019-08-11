## Leetcode
#### DFS
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
#### UnionFind
```
class Solution:
    def findCircleNum(self, M):
        n = len(M)
        d = {x : x for x in range(n)}
        for i in range(n):
            for j in range(i + 1, n):
                if M[i][j]:
                    rooti = self.find(i, d)
                    rootj = self.find(j, d)
                    d[rooti] = rootj
        return sum(1 for x, y in d.items() if x == y)
        
    def find(self, x, d):
        if d[x] == x: return x
        root = self.find(d[x], d)
        d[x] = root
        return root
```

```
class Solution:
    def findCircleNum(self, M):
        n = len(M)
        d = {x : -1 for x in range(n)}
        for i in range(n):
            for j in range(i + 1, n):
                if M[i][j]:
                    rooti = self.find(i, d)
                    rootj = self.find(j, d)
                    if rooti != rootj:
                        d[rooti] = rootj
        return list(d.values()).count(-1)
        
    def find(self, x, d):
        if d[x] == -1: return x
        root = self.find(d[x], d)
        d[x] = root
        return root
```
