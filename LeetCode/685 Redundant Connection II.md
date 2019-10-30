## Leetcode

```
class Solution:
    def findRedundantDirectedConnection(self, edges: List[List[int]]) -> List[int]:
        c1, c2, parent = None, None, dict()
        for u, v in edges:
            if v in parent:
                c1, c2 = [parent[v], v], [u, v]
                break
            parent[v] = u
        root = list(range(len(edges) + 1))
        
        def find(x):
            if root[x] != x:
                root[x] = find(root[x])
            return root[x]
        
        for u, v in edges:
            if [u, v] == c2: continue
            rootu, rootv = find(u), find(v)
            if rootu == rootv:
                if not c1:
                    return [u, v] 
                else:
                    return c1
            root[rootu] = root[rootv]
        return c2
```
