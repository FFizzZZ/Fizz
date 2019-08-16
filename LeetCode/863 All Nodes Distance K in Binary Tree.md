## Leetcode
#### BFS
```
class Solution(object):
    def distanceK(self, root, target, K):
        self.dfs(root)
        queue = collections.deque([(target, 0)])
        visited = {target}
        while queue:
            if queue[0][1] == K:
                return [node.val for node, d in queue]
            node, d = queue.popleft()
            for nxt in (node.left, node.right, node.par):
                if nxt and nxt not in visited:
                    visited.add(nxt)
                    queue.append((nxt, d + 1))
        return []

    def dfs(self, root, par = None):
        if root:
            root.par = par
            self.dfs(root.left, root)
            self.dfs(root.right, root)
```
#### Amazing!
```
class Solution(object):
    def distanceK(self, root, target, K):
        ans = []
        self.dfs(root, K, target, ans)
        return ans
    def dfs(self, node, K, target, ans):
        if not node: return -1
        if node is target:
            self.subtree_add(node, 0, K, ans)
            return 1
        else:
            L, R = self.dfs(node.left, K, target, ans), self.dfs(node.right, K, target, ans)
            if L != -1:
                if L == K: ans.append(node.val)
                elif L < K:
                    self.subtree_add(node.right, L + 1, K, ans)
                return L + 1
            if R != -1:
                if R == K: ans.append(node.val)
                elif R < K:
                    self.subtree_add(node.left, R + 1, K, ans)
                return R + 1
            return -1
        
    def subtree_add(self, node, dist, K, ans):
        if not node: return
        if dist == K:
            ans.append(node.val)
        else:
            self.subtree_add(node.left, dist + 1, K, ans)
            self.subtree_add(node.right, dist + 1, K ,ans)
```


```
class Solution(object):
    def distanceK(self, root, target, K):
        ans = []

        # Return distance from node to target if exists, else -1
        # Vertex distance: the # of vertices on the path from node to target
        def dfs(node):
            if not node:
                return -1
            elif node is target:
                subtree_add(node, 0)
                return 1
            else:
                L, R = dfs(node.left), dfs(node.right)
                if L != -1:
                    if L == K: 
                        ans.append(node.val)
                        # return -1
                    subtree_add(node.right, L + 1)
                    return L + 1
                elif R != -1:
                    if R == K: 
                        ans.append(node.val)
                        # return -1
                    subtree_add(node.left, R + 1)
                    return R + 1
                else:
                    return -1

        # Add all nodes 'K - dist' from the node to answer.
        def subtree_add(node, dist):
            if not node:
                return
            elif dist == K:
                ans.append(node.val)
            else:
                subtree_add(node.left, dist + 1)
                subtree_add(node.right, dist + 1)

        dfs(root)
        return ans
```

