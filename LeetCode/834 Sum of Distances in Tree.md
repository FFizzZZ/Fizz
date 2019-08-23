```
class Solution(object):
    def sumOfDistancesInTree(self, N, edges):
        graph = collections.defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)
        cnt = [1] * N
        ans = [0] * N
        
        def dfs(node, parent):
            for children in graph[node]:
                if children != parent:
                    dfs(children, node)
                    cnt[node] += cnt[children]
                    ans[node] += ans[children] + cnt[children]
        def f(node, parent):
            for children in graph[node]:
                if children != parent:
                    ans[children] = ans[node] + N - 2 * cnt[children]
                    f(children, node)
        
        dfs(0, None)
        f(0, None)
        
        return ans
```
