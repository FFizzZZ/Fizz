```
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        right = 1
        ans = []
        queue = collections.deque([root])
        while queue:
            tmp = []
            for _ in range(len(queue)):
                node = queue.popleft()
                tmp.append(node.val)
                if node.left: queue.append(node.left)
                if node.right: queue.append(node.right)
            if right: 
                ans.append(tmp)
            else:
                ans.append(tmp[::-1])
            right = 1 - right
        return ans
```
