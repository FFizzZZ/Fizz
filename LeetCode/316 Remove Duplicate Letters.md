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
###### Same Idea
```
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        d = collections.Counter(s)
        seen = set()
        ans = []
        for char in s:
            if not char in seen:
                while ans and ans[-1] > char and d[ans[-1]] > 1:
                    d[ans[-1]] -= 1
                    seen.discard(ans.pop())
                ans.append(char)
                seen.add(char)
            else:
                d[char] -= 1
        return ''.join(ans)
```













