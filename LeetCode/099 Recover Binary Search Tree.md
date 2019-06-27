## Inorder Traversal
```
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        stack = []
        first, second = None, None
        pre = None
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if pre and root.val < pre.val:
                if not first:
                    first = pre
                second = root            
            pre = root
            root = root.right
        first.val, second.val = second.val, first.val
```
## Leetcode
## Morris Traversal
```
class Solution:
    def recoverTree(self, root):
        first, second, prev = None, None, None 
        pred = None 
        cur = root
        while cur:
            if prev and cur.val < prev.val:
                if not first:
                    first = prev
                second = cur 
            if cur.left: 
                pred = cur.left
                while pred.right and pred.right != cur:
                    pred = pred.right
                if pred.right == cur: 
                    pred.right = None
                    prev = cur
                    cur = cur.right
                else: 
                    pred.right = cur
                    cur = cur.left
            else:
                prev = cur
                cur = cur.right
        first.val, second.val = second.val, first.val
```
