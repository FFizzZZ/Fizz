## BFS + stack
```
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        queue = [root]
        ans = []
        while queue:
            temp = []
            for _ in range(len(queue)):
                node = queue.pop(0)
                temp.append(node.val)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
            ans.insert(0, temp)
        return ans
```
## DFS + stack
```
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        stack = [(root, 1)]
        ans = []
        while stack:
            node, h = stack.pop()
            if h > len(ans): ans.insert(0, [])
            ans[-h].append(node.val)
            if node.right: stack.append((node.right, h + 1))
            if node.left: stack.append((node.left, h + 1))
        return ans
```
## Recurse
```
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        ans = []
        self.f(root, 1, ans)
        return ans
    def f(self, root, h, ans):
        if not root: return
        if h > len(ans): ans.insert(0, [])
        ans[-h].append(root.val)
        self.f(root.left, h + 1, ans)
        self.f(root.right, h + 1, ans)
```
