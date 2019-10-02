## Leetcode
```
class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key = len)
        dp = dict()
        m = len(words[0])
        for word in words:
            dp[word] = 1
            if len(word) > m:
                for i in range(len(word)):
                    tmp = word[:i] + word[i + 1:]
                    if tmp in dp:
                        dp[word] = max(dp[word], dp[tmp] + 1)
        return max(dp.values())
```

