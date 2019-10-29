## Leetcode

```
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        i = 0
        stack = []
        n = len(popped)
        for x in pushed:
            stack.append(x)
            while stack and stack[-1] == popped[i]:
                stack.pop()
                i += 1
        return i == n
```
