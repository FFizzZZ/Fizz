```
class Solution:
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        first, second, prev = None, None, None 
        stack = []
        cur = root
        while stack or cur:
            if cur: # visit curr's left subtree
                stack.append(cur)
                cur = cur.left
            else: # done left subtree of curr Node
                cur = stack.pop()
                # compare curr.val with prev.val if we have one
                if prev and cur.val < prev.val:
                    if not first: # incorrect smaller node is always found as prev node
                        first = prev
                    second = cur # incorrect larger node is always found as curr node
                # visit curr's right subtree
                prev = cur
                cur = cur.right
        first.val, second.val = second.val, first.val # recover swapped nodes
```
