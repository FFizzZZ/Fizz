```
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        d = {}
        for i, v in enumerate(inorder):
            d[v] = i
        return self.f(0, len(inorder) - 1, postorder, inorder, d)
    def f(self, i, j, postorder, inorder, d):
        if i > j: return None
        val = postorder.pop()
        node = TreeNode(val)
        index = d[val]
        node.right = self.f(index + 1, j, postorder, inorder, d)
        node.left = self.f(i, index - 1, postorder, inorder, d)
        return node
```

```
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not postorder: return None
        d = dict()
        for idx, val in enumerate(inorder):
            d[val] = idx
        head = TreeNode(postorder[-1])
        stack = [head]
        for i in range(len(inorder) - 2, -1, -1):
            val = postorder[i]
            node = TreeNode(val)
            if d[val] > d[stack[-1].val]:
                stack[-1].right = node
            else:
                while stack and d[val] < d[stack[-1].val]:
                    parent = stack.pop()
                parent.left = node
            stack.append(node)
        return head
```
