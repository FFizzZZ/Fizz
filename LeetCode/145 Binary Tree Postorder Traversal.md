```
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        self.f(root, ans)
        return ans
    def f(self, root, ans):
        if not root: return
        self.f(root.left, ans)
        self.f(root.right, ans)
        ans.append(root.val)
```

## Leetcode
## Reverse
```
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        if not root: return ans
        stack = [root]
        while stack:
            root = stack.pop()
            ans.insert(0, root.val)
            if root.left:
                stack.append(root.left)
            if root.right:
                stack.append(root.right)
        return ans
```
