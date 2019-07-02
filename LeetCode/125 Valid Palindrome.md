## Leetcode
```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while l < r:
            while l < r and not s[l].isalnum():
                l += 1
            while l < r and not s[r].isalnum():
                r -= 1
            if s[l].lower() != s[r].lower():
                return False
            l += 1
            r -= 1
        return True
```

```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = ''.join(re.findall(r'\w+', s.lower()))
        return (s == s[::-1])
```

```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        all_list = set(string.ascii_lowercase) | set(string.digits)
        s = s.lower()
        s = ''.join([char for char in s if char in all_list])
        if s == s[::-1]:
            return True
        else:
            return False
```
