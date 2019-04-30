```
# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.stack = []
        self.min_stack = []
    def push(self, node):
        # write code here
        self.stack.append(node)
        if not self.min_stack:
            self.min_stack.append(node)
        else:
            self.min_stack.append(min(node, self.min_stack[-1]))
    def pop(self):
        # write code here
        self.stack.pop()
        self.min_stack.pop()
    def top(self):
        # write code here
        return self.stack[-1]
    def min(self):
        # write code here
        return self.min_stack[-1]
```
