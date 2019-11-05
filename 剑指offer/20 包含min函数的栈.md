#### Two Stack
```
class Solution:
    def __init__(self):
        self.stack = []
        self.min_stack = []
    def push(self, node):
        self.stack.append(node)
        if not self.min_stack or self.min_stack[-1] > node:
            self.min_stack.append(node)
        else:
            self.min_stack.append(self.min_stack[-1])
    def pop(self):
        self.stack.pop()
        self.min_stack.pop()
    def top(self):
        return self.stack[-1]
    def min(self):
        return self.min_stack[-1]
```

```
class Solution:
    def __init__(self):
        self.stack = []
        self.min_stack = []
    def push(self, node):
        self.stack.append(node)
        if not self.min_stack or node <= self.min_stack[-1]:
            self.min_stack.append(node)
    def pop(self):
        if self.stack[-1] == self.min_stack[-1]:
            self.min_stack.pop()
        self.stack.pop()
    def top(self):
        return self.stack[-1]
    def min(self):
        return self.min_stack[-1]
```

#### One Stack
```
class Solution:
    def __init__(self):
        self.stack = []
        self.Min = float("inf")
    def push(self, node):
        if self.Min >= node:
            self.stack.append(self.Min)
            self.Min = node
        self.stack.append(node)
    def pop(self):
        if self.stack.pop() == self.Min:
            self.Min = self.stack.pop()
    def top(self):
        return self.stack[-1]
    def min(self):
        return self.Min
```
