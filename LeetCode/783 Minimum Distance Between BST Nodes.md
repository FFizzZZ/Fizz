#### Stack
```
class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        pre = float("-inf")
        ans = float("inf")
        stack = []
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            val = root.val - pre
            if val < ans: ans = val
            pre = root.val
            root = root.right
        return ans
```

#### Morris Traversal
```
class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        pre = float("-inf")
        ans = float("inf")
        while root:
            if root.left:
                tmp = node = root.left
                while node.right and node.right != root:
                    node = node.right
                if node.right == root:
                    node.right = None
                    val = root.val - pre
                    if val < ans: ans = val
                    pre = root.val
                    root = root.right
                else:
                    node.right = root
                    root = tmp
            else:
                val = root.val - pre
                if val < ans: ans = val
                pre = root.val
                root = root.right
        return ans
```
