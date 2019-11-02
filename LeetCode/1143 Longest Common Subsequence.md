## Leetcode
#### Dynamic Programming
```
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n1, n2 = len(text1), len(text2)
        dp = [[0] * (n2 + 1) for _ in range(n1 + 1)]
        
        for i in range(1, n1 + 1):
            for j in range(1, n2 + 1):
                if text1[i - 1] == text2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        return dp[-1][-1]
```
###### Optimized Version
```
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n1, n2 = len(text1), len(text2)
        dp = [0] * (n2 + 1)
        
        for i in range(1, n1 + 1):
            pre = 0
            for j in range(1, n2 + 1):
                tmp = dp[j]
                if text1[i - 1] == text2[j - 1]:
                    dp[j] = pre + 1
                else:
                    dp[j] = max(dp[j], dp[j - 1])
                pre = tmp
        return dp[-1]
```

```
class Solution:
    def longestCommonSubsequence(self, s1: str, s2: str) -> int:
        d = collections.defaultdict(list)
        for idx, char in reversed(list(enumerate(s2))):
            d[char].append(idx)
        dp = [0] * (len(s2) + 1)
        for char in s1:
            for j in d[char]:
                dp[j + 1] = max(dp[:j + 1]) + 1
        return max(dp)
```

#### FASTEST! Change the question into finding longest increasing subsequence. SO AMAZING!
```
class Solution:
    def longestCommonSubsequence(self, s1: str, s2: str) -> int:
        d = collections.defaultdict(list)
        for idx, char in reversed(list(enumerate(s2))):
            d[char].append(idx)
        nums = []
        for char in s1:
            if char in d:
                nums.extend(d[char])
        ans = []
        for x in nums:
            idx = bisect.bisect_left(ans, x)
            if idx == len(ans):
                ans.append(x)
            else:
                ans[idx] = x
        return len(ans)
```
