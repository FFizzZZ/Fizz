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
        head = TreeNode(postorder[-1])
        stack = [head]
        j = -1
        for i in range(len(postorder) - 2, -1, -1):
            node = TreeNode(postorder[i])
            temp = None
            while stack and stack[-1].val == inorder[j]:
                temp = stack.pop()
                j -= 1
            if temp:
                temp.left = node
            else:
                stack[-1].right = node
            stack.append(node)
        return head
```
