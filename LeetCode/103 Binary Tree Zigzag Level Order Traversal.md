```
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        right = 1
        ans = []
        queue = [root]
        while queue:
            res = []
            for _ in range(len(queue)):
                root = queue.pop(0)
                res.append(root.val)
                if root.left: queue.append(root.left)
                if root.right: queue.append(root.right)
            if right:
                ans.append(res)
            else:
                ans.append(res[::-1])   
            right = 1 - right
        return ans
```
