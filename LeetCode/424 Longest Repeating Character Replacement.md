## Leetcode

```
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        d = collections.defaultdict(int)
        start = 0
        ans = cnt = 0
        for end, char in enumerate(s):
            d[char] += 1
            cnt = max(cnt, d[char])
            while end - start + 1 - cnt > k:
                d[s[start]] -= 1
                start += 1
            ans = max(ans, end - start + 1)
        return ans
```
#### FASTEST       
```
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        d = collections.defaultdict(int)
        start = 0
        Max = 0
        for end, char in enumerate(s):
            d[char] += 1
            Max = max(Max, d[char])
            if Max + k < end - start + 1:
                d[s[start]] -= 1
                start += 1
        return len(s) - start
```
