## Leetcode

```
class Solution:
    def trimBST(self, root: TreeNode, L: int, R: int) -> TreeNode:
        if not root: return
        if root.val > R:
            return self.trimBST(root.left, L, R)
        elif root.val < L:
            return self.trimBST(root.right, L, R)
        else:
            root.left = self.trimBST(root.left, L, R)
            root.right = self.trimBST(root.right, L, R)
            return root
```
