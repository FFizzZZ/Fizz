## Leetcode

```
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        stack = []
        visited = set()
        last = {char: idx for idx, char in enumerate(s)}
        for idx, char in enumerate(s):
            if char not in visited:
                while stack and stack[-1] > char and last[stack[-1]] > idx:
                    visited.discard(stack.pop())
                visited.add(char)
                stack.append(char)
        return "".join(stack)
```













