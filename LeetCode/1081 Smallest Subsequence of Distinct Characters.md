## Leetcode

```
class Solution:
    def smallestSubsequence(self, text: str) -> str:
        last = {char: idx for idx, char in enumerate(text)}
        stack = []
        visited = set()
        for idx, char in enumerate(text):
            if char in visited:
                continue
            while stack and stack[-1] > char and last[stack[-1]] > idx:
                visited.remove(stack.pop())
            stack.append(char)
            visited.add(char)
        return "".join(stack)
```
