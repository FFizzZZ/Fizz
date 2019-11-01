## Leetcode

#### Breadth-First Search
```
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        queue = [(root, 0, 0)]
        start = cur = 0
        ans = 1
        for node, depth, idx in queue:
            if node:
                queue.append((node.left, depth + 1, 2 * idx + 1))
                queue.append((node.right, depth + 1, 2 * idx + 2))
                if depth > cur:
                    cur = depth
                    start = idx
                val = idx - start + 1
                if val > ans: ans = val
        return ans
```

#### Depth-First Search
```
class Solution:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        self.ans = 0
        left = dict()
        def dfs(node, depth = 0, pos = 0):
            if node:
                left.setdefault(depth, pos)
                val = pos - left[depth] + 1
                if val > self.ans: self.ans = val
                dfs(node.left, depth + 1, 2 * pos + 1)
                dfs(node.right, depth + 1, 2 * pos + 2)
        dfs(root)
        return self.ans
```
