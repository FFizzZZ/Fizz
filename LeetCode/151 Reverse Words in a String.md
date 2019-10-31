```
class Solution:
    def reverseWords(self, s: str) -> str:
        string = s.split()
        return " ".join(string[::-1])
```
