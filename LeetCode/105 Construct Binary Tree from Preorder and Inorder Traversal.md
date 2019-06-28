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
This one use preorder.pop(). It is convenient that we don't need to calculate the start of preorder.
```
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        return self.f(0, len(inorder) - 1, preorder, inorder)
    def f(self, j, k, preorder, inorder):
        if j > k: return None
        val = preorder.pop(0)
        node = TreeNode(val)
        index = inorder.index(val)
        node.left = self.f(j, index - 1, preorder, inorder)
        node.right = self.f(index + 1, k, preorder, inorder)
        return node
```
## Optimized version
This one stores index in the dictionary and use iter(), which saves time and memory usage.
```
class Solution(object):
    def buildTree(self, preorder, inorder):
        d = {}
        for i, v in enumerate(inorder):
            d[v] = i
        iterator = iter(preorder)
        return self.f(0, len(inorder) - 1, iterator, d)
    def f(self, l, r, iterator, d):
        if l > r: return None
        val = next(iterator)
        node = TreeNode(val)
        index = d[val]
        node.left = self.f(l, index - 1, iterator, d)
        node.right = self.f(index + 1, r, iterator, d)
        return node
```
