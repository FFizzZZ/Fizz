### Recurse with memorization
```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        d = {}
        return self.f(0, s, wordDict, d)
    def f(self, index, s, wordDict, d):
        if index == len(s): return True
        if index in d: return d[index]
        ans = False
        for x in wordDict:
            l = len(x)
            if s[index:index + l] == x and self.f(index + l, s, wordDict, d):
                ans = True
                break
        d[index] = ans
        return ans
```
### Dynamic Programming
```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True
        for i in range(n + 1):
            for x in wordDict:
                l = len(x)
                if dp[i] and i + l <= n and x == s[i:i + l]:
                    dp[i + l] = True
        return dp[-1]
```
        

## Leetcode
#### Dynamic Programming
```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [False] * (len(s) + 1)
        dp[0] = True
        for i in range(1, len(s) + 1):
            for j in range(i):
                if dp[j] and s[j:i] in wordDict:
                    dp[i] = True
                    break
        return dp[-1]
```

```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True
        for i in range(n + 1):
            for x in wordDict:
                l = len(x)
                if l <= i and dp[i - l] and x == s[i - l:i]:
                    dp[i] = True
                    break
        return dp[-1]
```
        
        
        
        

