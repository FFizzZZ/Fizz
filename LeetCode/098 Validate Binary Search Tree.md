```
class Solution(object):
    def isValidBST(self, root, left = float('inf'), right = float('-inf')):
        if not root: return True
        if root.val >= left or root.val <= right:
            return False
        return self.isValidBST(root.left, root.val, right) and self.isValidBST(root.right, left, root.val)
```
    
---------------------------

## 检验中序排序是否严格递增
```
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        inorder = []
        def f(node):
            if not node:
                return
            f(node.left)
            inorder.append(node.val)
            f(node.right)
        f(root)
        for i in range(1, len(inorder)):
            if inorder[i-1] >= inorder[i]:
                return False
        return True
```
## 上一个方法的改进，只需记录最后一个inorder值即可
```
class Solution:
    def isValidBST(self, root):
        stack, inorder = [], float('-inf')
        
        while stack or root:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            # If next element in inorder traversal
            # is smaller than the previous one
            # that's not BST.
            if root.val <= inorder:
                return False
            inorder = root.val
            root = root.right

        return True
```
## Iteration (stack)
```
class Solution:
    def isValidBST(self, root):
        if not root:
            return True     
        stack = [(root, -sys.maxsize, sys.maxsize), ] 
        while stack:
            root, lower_limit, upper_limit = stack.pop()
            if root.right:
                if root.right.val > root.val:
                    if root.right.val >= upper_limit:
                        return False
                    stack.append((root.right, root.val, upper_limit))
                else:
                    return False
            if root.left:
                if root.left.val < root.val:
                    if root.left.val <= lower_limit:
                        return False
                    stack.append((root.left, lower_limit, root.val))
                else:
                    return False
        return True  
```
