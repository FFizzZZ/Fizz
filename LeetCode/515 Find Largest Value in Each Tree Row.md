```
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        if not root: return []
        ans = []
        stack = collections.deque([root])
        while stack:
            Max = float("-inf")
            for _ in range(len(stack)):
                node = stack.popleft()
                if node.val > Max: Max = node.val
                if node.left: stack.append(node.left)
                if node.right: stack.append(node.right)
            ans.append(Max)
        return ans
```
