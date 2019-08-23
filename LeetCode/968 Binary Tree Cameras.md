## Leetcode
#### Dynamic Programming
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
#### Greedy
```
class Solution(object):
    def minCameraCover(self, root):
        self.ans = 0
        visited = {None}
        self.f(root, None, visited)
        return self.ans
        
    def f(self, node, par, visited):
        if node:
            self.f(node.left, node, visited)
            self.f(node.right, node, visited)
            
            if not par and node not in visited or node.left not in visited or node.right not in visited:
                self.ans += 1
                visited.update([node, par, node.left, node.right])
```

#### FASTEST
##### GREAT IDEA
```
class Solution(object):
    def minCameraCover(self, root):
        self.cnt = 0
        def f(node):
            if not node: return -1
            l = f(node.left)
            r = f(node.right)
            if l == 0 or r == 0:
                self.cnt += 1
                return 1
            if r == 1 or l == 1:
                return -1
            else:
                return 0
        return (f(root) == 0) + self.cnt
```
