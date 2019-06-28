## Leetcode
## Recurse
```
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        return self.f(0, 0, len(inorder) - 1, preorder, inorder)
    def f(self, i, j, k, preorder, inorder):
        if j > k: return None
        val = preorder[i]
        node = TreeNode(val)
        index = inorder.index(val)
        node.left = self.f(i + 1, j, index - 1, preorder, inorder)
        node.right = self.f(i + index - j + 1, index + 1, k, preorder, inorder)
        return node
```
