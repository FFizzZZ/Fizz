## Leetcode
```
class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key = len)
        dp = dict()
        for word in words:
            dp[word] = max(dp.get(word[:i] + word[i + 1:], 0) + 1 for i in range(len(word)))
        return max(dp.values()) if dp else 0
```
