## Leetcode

```
class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        values = [(len(s[0]), s[1]) for s in re.findall("(-*)(\d+)", S)]
        stack = []
        for level, val in values:
            while len(stack) > level:
                stack.pop()
            node = TreeNode(val)
            if stack and stack[-1].left is None:
                stack[-1].left = node
            elif stack:
                stack[-1].right = node
            stack.append(node)
        return stack[0]
```

```
class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        self.values = [(len(s[0]), s[1]) for s in re.findall("(-*)(\d+)", S)][::-1]
        return self.f(0)
    
    def f(self, level):
        if not self.values or level != self.values[-1][0]:
            return None
        node = TreeNode(self.values.pop()[1])
        node.left = self.f(level + 1)
        node.right = self.f(level + 1)
        return node
```
