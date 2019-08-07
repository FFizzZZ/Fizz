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
