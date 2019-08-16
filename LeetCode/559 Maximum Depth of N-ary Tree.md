```
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root: return 0
        ans = 0
        for node in root.children:
            tmp = self.maxDepth(node)
            if tmp > ans: ans = tmp
        return 1 + ans
```

## Leetcode
```
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        cnt = 0
        queue = [root] if root else []
        while queue:
            cnt += 1
            queue = [children for node in queue for children in node.children]
        return cnt
```
