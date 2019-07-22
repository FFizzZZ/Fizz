```
class Solution:
    def titleToNumber(self, s: str) -> int:
        l = len(s)
        ans = 0
        for i in range(l):
            val = ord(s[l - i - 1]) - ord('A')
            ans += val * 26 ** i + 26 ** i
        return ans
```
