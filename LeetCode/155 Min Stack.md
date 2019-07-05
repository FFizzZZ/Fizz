```
class MinStack(object):
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
        self.min = float('inf')
    def push(self, x):
        self.stack1.append(x)
        if x < self.min:
            self.min = x
        self.stack2.append(self.min)

    def pop(self):
        val = self.stack1.pop()
        self.stack2.pop()
        if val == self.min:
            self.min = self.stack2[-1] if self.stack2 else float('inf')
    def top(self):
        return self.stack1[-1]
    def getMin(self):
        return self.stack2[-1]
```
