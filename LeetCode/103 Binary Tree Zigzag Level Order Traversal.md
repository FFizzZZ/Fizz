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
                if right:
                    res.append(root.val)
                else:
                    res.insert(0, root.val)
                if root.left: queue.append(root.left)
                if root.right: queue.append(root.right) 
            ans.append(res)
            right = 1 - right
        return ans
```
