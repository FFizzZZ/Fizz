## Leetcode
```
class Solution:
    def longestSubstring(self, s, k):
        for c in set(s):
            if s.count(c) < k:
                return max(self.longestSubstring(t, k) for t in s.split(c))
        return len(s)
```

```
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
            counter = collections.Counter(s)
            for key,val in counter.items():
                if val < k:
                    s = s.replace(key,'-')
            if not '-' in s:
                return len(s)
            substr_set = set(s.split('-'))
            ans = 0
            for substr in substr_set:
                tmp = self.longestSubstring(substr, k)
                if tmp > ans:
                    ans = tmp
            return ans
```

```
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        ans = 0
        for N in range(1, 27):
            d = collections.defaultdict(int)
            l, r = 0, 0
            unique = 0
            nolessthanK = 0
            while r < len(s):
                if unique <= N:
                    char = s[r]
                    if d[char] == 0:
                        unique += 1
                    d[char] += 1
                    if d[char] == k:
                        nolessthanK += 1
                    r += 1
                else:
                    char = s[l]
                    if d[char] == k:
                        nolessthanK -= 1
                    d[char] -= 1
                    if d[char] == 0:
                        unique -= 1
                    l += 1
                if unique == N == nolessthanK:
                    ans = max(ans, r - l)
        return ans
```

```
class Solution:
    def longestSubstring(self, s: str, k: int) -> int:
        ans = 0
        for N in range(1, 27):
            tmp = self.f(s, k, N)
            if tmp > ans: ans = tmp
        return ans
    def f(self, s, k, N):
        d = collections.defaultdict(int)
        unique, cnt = 0, 0
        l, r = 0, 0
        ans = 0
        while r < len(s):
            char = s[r]
            if d[char] == 0: unique += 1
            d[char] += 1
            if d[char] == k: cnt += 1
            r += 1
            
            while unique > N:
                char = s[l]
                if d[char] == k: cnt -= 1
                d[char] -= 1
                if d[char] == 0: unique -= 1
                l += 1
            
            if N == unique == cnt:
                tmp = r - l
                if tmp > ans: ans = tmp
        return ans
```
