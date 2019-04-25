# stack
```
class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        if not root: return []
        ans = {}
        stack = []
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            ans[root.val] = ans.get(root.val, 0) + 1
            root = root.right
        m = max(ans.values())
        res = []
        for i in ans:
            if ans[i] == m:
                res.append(i)
        return res
```

# recursive
```
class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        if not root: return []
        ans = {}
        def f(node):
            if not node:
                return
            f(node.left)
            ans[node.val] = ans.get(node.val, 0) + 1
            f(node.right)
        f(root)
        m = max(ans.values())
        res = []
        for i in ans:
            if ans[i] == m:
                res.append(i)
        return res
```
