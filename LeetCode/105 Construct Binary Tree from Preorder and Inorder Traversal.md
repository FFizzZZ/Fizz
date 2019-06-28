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
This one use preorder.pop(). It is convenient that we don't need to calculate the index of preorder.
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
### Recurse: Optimized version
This one stores index in the dictionary so that it can spend less time.  
Also, it use iter(), it is such a good idea that it would change the original preorder.
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
## Iteration
So difficult .... It takes me long time to understand. Oh my god!
```
class Solution(object):
    def buildTree(self, preorder, inorder):
        if not preorder: return None   
        head = TreeNode(preorder[0])
        stack = [head]
        i = 1
        j = 0
        for i in range(1, len(preorder)):
            temp = None
            t = TreeNode(preorder[i])
            while stack and stack[-1].val == inorder[j]:
                temp = stack.pop()
                j += 1
            if temp:
                temp.right = t
            else:
                stack[-1].left = t
            stack.append(t)        
        return head
```

```
class Solution(object):
    def buildTree(self, preorder, inorder):
        if not preorder: return None
        d = {}
        for i, v in enumerate(inorder):
            d[v] = i
        root = TreeNode(preorder[0])
        stack = [root]
        for i in range(1, len(preorder)):
            val = preorder[i]
            node = TreeNode(val)
            if d[val] < d[stack[-1].val]:
                stack[-1].left = node
            else:
                while stack and d[val] > d[stack[-1].val]:
                    parent = stack.pop()
                parent.right = node
            stack.append(node)
        return root
```
