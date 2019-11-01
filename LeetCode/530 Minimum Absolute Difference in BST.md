```
class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        self.ans = float("inf")
        self.pre = float("inf")
        def inorder(root):
            if not root: return
            inorder(root.left)
            val = abs(root.val - self.pre)
            if val < self.ans: self.ans = val
            self.pre = root.val
            inorder(root.right)
        inorder(root)
        return self.ans
```

## Leetcode
```
class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        inorder = []
        stack = []
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            inorder.append(root.val)
            root = root.right
        ans = float("inf")
        for i in range(1, len(inorder)):
            val = abs(inorder[i] - inorder[i - 1])
            if val < ans: ans = val
        return ans
```
