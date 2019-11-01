```
class Solution:
    def insertIntoMaxTree(self, root: TreeNode, val: int) -> TreeNode:
        def dfs(root):
            if not root: return []
            return dfs(root.left) + [root.val] + dfs(root.right)
        A = dfs(root)
        A.append(val)
        def make(A):
            if not A: return None
            Max = max(A)
            idx = A.index(Max)
            node = TreeNode(Max)
            node.left = make(A[:idx])
            node.right = make(A[idx + 1:])
            return node
        return make(A)
```

## Leetcode

#### Recursion
```
class Solution:
    def insertIntoMaxTree(self, root, val):
        if root and root.val > val:
            root.right = self.insertIntoMaxTree(root.right, val)
            return root
        node = TreeNode(val)
        node.left = root
        return node
```

#### Iteration
```
class Solution:
    def insertIntoMaxTree(self, root, val):
        pre, cur = None, root
        while cur and cur.val > val:
            pre, cur = cur, cur.right
        node = TreeNode(val)
        node.left = cur
        if pre:
            pre.right = node
        return root if root.val > val else node
```
