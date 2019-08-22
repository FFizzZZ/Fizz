## Leetcode
* [State 0] Strict subtree: All the nodes below this node are covered, but not this node.
* [State 1] Normal subtree: All the nodes below and including this node are covered, but there is no camera here.
* [State 2] Placed camera: All the nodes below and including this node are covered, and there is a camera here 
```
class Solution(object):
    def minCameraCover(self, root):
        return min(self.f(root)[1:])
        
    def f(self, node):
        if not node:
            return 0, 0, float('inf')
        left = self.f(node.left)
        right = self.f(node.right)
        
        dp0 = left[1] + right[1]
        dp1 = min(left[2] + min(right[1:]), right[2] + min(left[1:]))
        dp2 = 1 + min(left) + min(right)
        
        return dp0, dp1, dp2
```
