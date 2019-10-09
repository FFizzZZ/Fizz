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
## Iteration
Use pre to keep track of the state of each node in the stack
```
class Solution:
    def postorderTraversal(self, root):
        ans = []
        stack = []
        while root or stack:
            if root:
                stack.append(root)
                root = root.left
            else:
                node = stack[-1]
                if not node.right or node.right == pre:
                    stack.pop()
                    ans.append(node.val)
                    pre = node
                else:
                    root = node.right
        return ans
```
Similarly
```
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        stack = []
        while root or stack:
            while root:
                stack.append([root, False])
                root = root.left
            node, visited = stack[-1]
            if visited:
                ans.append(node.val)
                stack.pop()
            else:
                stack[-1][1] = True
                root = node.right
        return ans
```

```
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        if not root: return []
        ans = []
        stack = [(root, False)]
        while stack:
            node, visited = stack.pop()
            if visited:
                ans.append(node.val)
            else:
                stack.append((node, True))            
                if node.right:
                    stack.append((node.right, False))
                if node.left:
                    stack.append((node.left, False))
        return ans
```

## Reverse of Preorder
Some people says that this method is kind of cheating.
```
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        ans = []
        stack = []
        while root or stack:
            if root:
                ans.insert(0, root.val)
                stack.append(root)
                root = root.right
            else:
                root = stack.pop()
                root = root.left
        return ans
```
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
