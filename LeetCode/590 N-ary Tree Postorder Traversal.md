```
class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        if not root: return []
        ans = []
        self.f(root, ans)
        return ans
    def f(self, node, ans):
        for children in node.children:
            self.f(children, ans)
        ans.append(node.val)
```

```
class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        if not root:
            return []
        stack, res = [root], []
        while stack:
            curr = stack.pop()
            res.append(curr.val)
            for child in curr.children:
                stack.append(child)
        return res[::-1]
```

