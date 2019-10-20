## Leetcode
```
class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        first = 1
        second = 9 if s[0] == "*" else (0 if s[0] == "0" else 1)
        pre = s[0]
        M = 10 ** 9 + 7
        for char in s[1:]:
            if char == "*":
                cur = second * 9
                if pre == "1":
                    cur = (cur + 9 * first) % M
                elif pre == "2":
                    cur = (cur + 6 * first) % M
                elif pre == "*":
                    cur = (cur + 15 * first) % M
            else:
                cur = 0 if char == "0" else second
                if pre == "1":
                    cur = (cur + first) % M
                elif pre == "2" and char <= "6":
                    cur = (cur + first) % M
                elif pre == "*":
                    cur = (cur + (2 if char <= "6" else 1) * first) % M
            first, second = second, cur
            pre = char
        return second
```
