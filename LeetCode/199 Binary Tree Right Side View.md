## Leetcode
#### BFS
```
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root: return []
        ans = []
        queue = collections.deque([root])
        while queue:
            for _ in range(len(queue)):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            ans.append(node.val)
        return ans
```
#### DFS
```
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        ans = []
        self.dfs(root, 0, ans)
        return ans
    def dfs(self, node, depth, ans):
        if node:
            if depth == len(ans):
                ans.append(node.val)
            depth += 1
            self.dfs(node.right, depth, ans)
            self.dfs(node.left, depth, ans)
```

```
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        right = dict()
        stack = [(root, 0)]
        while stack:
            node, depth = stack.pop()
            if node:
                right[depth] = node.val
                stack.append((node.right, depth + 1))
                stack.append((node.left, depth + 1))
        return [right[key] for key in sorted(right.keys())]
```

