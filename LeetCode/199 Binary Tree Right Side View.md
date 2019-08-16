```
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root: return []
        ans = []
        queue = [root]
        while queue:
            tmp = []
            ans.append(queue[-1].val)
            for node in queue:
                if node.left:
                    tmp.append(node.left)
                if node.right:
                    tmp.append(node.right)
            queue = tmp
        return ans
```
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root: return []
        ans = []
        queue = collections.deque([root])
        while queue:
            for _ in range(len(queue)):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            ans.append(node.val)
        return ans

## Leetcode
#### BFS
```
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root: return []
        ans = []
        queue = collections.deque([root])
        while queue:
            for _ in range(len(queue)):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            ans.append(node.val)
        return ans
```
#### DFS
```
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        right = dict()
        stack = [(root, 0)]
        while stack:
            node, depth = stack.pop()
            if node:
                right[depth] = node.val
                stack.append((node.right, depth + 1))
                stack.append((node.left, depth + 1))
        return [right[key] for key in sorted(right.keys())]
```
