## Iteration
```
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        queue = [root]
        ans = []
        while queue:
            res = []
            for _ in range(len(queue)):
                node = queue.pop(0)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
                res.append(node.val)
            ans.append(res)
        return ans
```
## Recurse
```
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        ans = []
        self.f(root, 0, ans)
        return ans
    def f(self, root, h, ans):
        if not root: return
        if h == len(ans): ans.append([])
        ans[h].append(root.val)
        self.f(root.left, h + 1, ans)
        self.f(root.right, h + 1, ans)
```
