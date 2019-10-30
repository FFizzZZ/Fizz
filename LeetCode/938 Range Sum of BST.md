```
class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        if not root:
            return 0
        ans = root.val if L <= root.val <= R else 0
        if root.val < L:
            ans += self.rangeSumBST(root.right, L, R)
        elif root.val > R:
            ans += self.rangeSumBST(root.left, L, R)
        else:
            ans += self.rangeSumBST(root.left, L, R) + self.rangeSumBST(root.right, L, R)
        return ans
```

## Leetcode
```
class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        def dfs(node):
            if node:
                if L <= node.val <= R:
                    self.ans += node.val
                if L < node.val:
                    dfs(node.left)
                if R > node.val:
                    dfs(node.right)
        self.ans = 0
        dfs(root)
        return self.ans
```

```
class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        if not root: return 0
        ans = 0
        stack = [root]
        while stack:
            node = stack.pop()
            if L <= node.val <= R:
                ans += node.val
            if node.left and node.val > L:
                stack.append(node.left)
            if node.right and node.val < R:
                stack.append(node.right)
        return ans
```
