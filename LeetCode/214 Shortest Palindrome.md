```
class Solution:
    def shortestPalindrome(self, s: str) -> str:
        n = len(s)
        for i in range(n + 1):
            left, right = s[: n - i], s[n - i:]
            if left == left[::-1]:
                return right[::-1] + s
```

## Leetcode
#### Two Pointers and Recursion
The trick is that longest palindrome substring from the beginning is within range [0, i).
```
class Solution:
    def shortestPalindrome(self, s):
        n = len(s)
        if n == 1: return s
        
        i = 0
        for j in range(n - 1, -1, -1):
            if s[i] == s[j]:
                i += 1
                
        if i == n: return s
        return s[i:][::-1] + self.shortestPalindrome(s[:i]) + s[i:]
```
