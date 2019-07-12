```
class Solution:
    def rob(self, root: TreeNode) -> int:
        d = {}
        return self.f(root, True, d)
    def f(self, root, state, d):
        if not root: return 0
        if (root, state) in d: return d[(root, state)]
        if state:
            val1 = root.val + self.f(root.left, False, d) + self.f(root.right, False, d)
            val2 = self.f(root.left, True, d) + self.f(root.right, True, d)
            ans = val1 if val1 > val2 else val2
        else:
            ans = self.f(root.left, True, d) + self.f(root.right, True, d)
        d[(root, state)] = ans
        return ans
```

## Leetcode
```
class Solution:
    def rob(self, root: TreeNode) -> int:
        return self.f(root, {})
    def f(self, root, d):
        if not root: return 0
        if root in d: return d[root]
        val = root.val
        if root.left:
            val += self.f(root.left.left, d) + self.f(root.left.right, d)
        if root.right:
            val += self.f(root.right.left, d) + self.f(root.right.right, d)
        temp = self.f(root.left, d) + self.f(root.right, d)
        if temp > val:
            val = temp
        d[root] = val
        return val
```

```
class Solution:
    def rob(self, root: TreeNode) -> int:
        return max(self.f(root))
    def f(self, root):
        if not root: return [0, 0]
        left= self.f(root.left)
        right = self.f(root.right)
        ans = [0, 0]
        ans[0] = max(left) + max(right)
        ans[1] = root.val + left[0] + right[0]
        return ans
```
