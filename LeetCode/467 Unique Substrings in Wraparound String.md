## Leetcode
```
class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        n = len(p)
        if n == 0: return 0
        dp = [1] * n
        d = collections.defaultdict(int)
        d[p[0]] = 1
        for i in range(1, n):
            cur = p[i]
            if ord(cur) - ord(p[i - 1]) == 1 or cur == "a" and p[i - 1] == "z":
                dp[i] = dp[i - 1] + 1
            d[cur] = max(d[cur], dp[i])
        return sum(d.values())   
```
#### FASTEST
```
class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        if not p: return 0
        d = collections.defaultdict(int)
        nxt = dict(zip('abcdefghijklmnopqrstuvwxyz', 'bcdefghijklmnopqrstuvwxyza'))
        pre = p[0]
        d[pre] = cnt = 1
        for char in p[1:]:
            if char in nxt[pre]:
                cnt += 1
            else:
                cnt = 1
            if d[char] < cnt:
                d[char] = cnt
            pre = char
        return sum(d.values())
```
