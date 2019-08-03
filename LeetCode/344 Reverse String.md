```
class Solution:
    def reverseString(self, s: List[str]) -> None:
        for i in range(len(s) // 2):
            s[i], s[~i] = s[~i], s[i]
```

```
class Solution:
    def reverseString(self, s: List[str]) -> None:
        s.reverse()
```

```
class Solution:
    def reverseString(self, s: List[str]) -> None:
        s[:] = s[::-1]
```
