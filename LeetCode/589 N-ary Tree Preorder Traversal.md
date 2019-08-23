```
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if not root: return []
        ans = []
        self.f(root, ans)
        return ans       
    def f(self, node, ans):
        ans.append(node.val)
        for i in node.children:
            self.f(i, ans)
```

## Leetcode
```
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        array = []
        stack = [root]
        while stack:
            node = stack.pop()
            if node:
                array.append(node.val)
                stack += [node for node in node.children[::-1] if node]
        return array
```
