```
class Solution:
    def recoverTree(self, root):
        first, second, prev = None, None, None 
        stack = []
        cur = root
        while stack or cur:
            if cur:
                stack.append(cur)
                cur = cur.left
            else:
                cur = stack.pop()
                if prev and cur.val < prev.val:
                    if not first:       # incorrect smaller node is always found as prev node
                        first = prev
                    second = cur        # incorrect larger node is always found as curr node
                prev = cur
                cur = cur.right
        first.val, second.val = second.val, first.val
```
