```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        self.ans = None
        self.f(root, p, q)
        return self.ans
        
    def f(self, root, p, q):
        if not root: return 0
        cur = (root == q) + (root == p)
        left = self.f(root.left, p, q)
        right = self.f(root.right, p, q)
        tmp = cur + left + right
        if tmp == 2 and not self.ans:
            self.ans = root
        return tmp
```
        
## Leetcode
#### Recurse
```
class Solution:
    def lowestCommonAncestor(self, root, p, q):
        val = root.val
        pval, qval = p.val, q.val
        
        if pval > val and qval > val:
            return self.lowestCommonAncestor(root.right, p, q)
        elif qval < val and pval < val:    
            return self.lowestCommonAncestor(root.left, p, q)
        else:
            return root
```
#### Iteration
```
class Solution:
    def lowestCommonAncestor(self, root, p, q):
        val = root.val
        pval, qval = p.val, q.val
        
        while root:
            val = root.val
            if val > pval and val > qval:
                root = root.left
            elif val < pval and val < qval:
                root = root.right
            else:
                return root
```
