## Leetcode

```
class Solution(object):
    def smallestFromLeaf(self, root):
        self.ans = "~"
        def dfs(node, path):
            if node:
                path.append(chr(node.val + ord("a")))
                if not node.left and not node.right:
                    tmp = "".join(reversed(path))
                    if tmp < self.ans: self.ans = tmp
                dfs(node.left, path)
                dfs(node.right, path)
                path.pop()
        dfs(root, [])
        return self.ans
```

```
class Solution:
    def smallestFromLeaf(self, root: TreeNode) -> str:
        self.ans = chr(ord('z') + 1)
        def dfs(node, path):
            if not node: return
            path = chr(ord('a') + node.val) + path
            if not node.left and not node.right:
                self.ans = min(self.ans, path)
            else:
                dfs(node.left, path)
                dfs(node.right, path)
        dfs(root, '')
        return self.ans
```
