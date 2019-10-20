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
                tmp = 9 * second
                if pre == "1":
                    tmp = (tmp + 9 * first) % M
                elif pre == "2":
                    tmp = (tmp + 6 * first) % M
                elif pre == "*":
                    tmp = (tmp + 15 * first) % M
            else:
                tmp = second if char != "0" else 0
                if pre == "1":
                    tmp = (tmp + first) % M
                elif pre == "2" and char <= "6":
                    tmp = (tmp + first) % M
                elif pre == "*":
                    tmp = (tmp + (2 if char <= "6" else 1) * first) % M
            first, second = second, tmp
            pre = char
        return second
```
