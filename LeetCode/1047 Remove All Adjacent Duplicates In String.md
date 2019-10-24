```
class Solution:
    def removeDuplicates(self, S: str) -> str:
        stack = []
        for char in S:
            if stack and stack[-1] == char:
                stack.pop()
            else:
                stack.append(char)
        return "".join(stack)
```

## Leetcode
```
class Solution:
    def removeDuplicates(self, S: str) -> str:
        duplicates = {2 * ch for ch in string.ascii_lowercase}
        pre = -1
        while pre != len(S):
            pre = len(S)
            for d in duplicates:
                S = S.replace(d, "")
        return S
```

```
class Solution:
    def removeDuplicates(self, S):
        _sub=re.compile(r'(.)\1').sub
        last = ''
        while S != last:
            last, S = S, _sub('', S)
        return S
```
