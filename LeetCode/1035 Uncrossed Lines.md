

## Leetcode

#### It's actually the LCS problem!
#### Dynamic Programming
```
class Solution:
    def maxUncrossedLines(self, A, B) -> int:
        m, n = len(A), len(B)
        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if A[i - 1] == B[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
        return dp[-1][-1]
```

```
class Solution:
    def maxUncrossedLines(self, A: List[int], B: List[int]) -> int:
        m, n = len(A), len(B)
        dp = [0] * (n + 1)
        for i in range(1, m + 1):
            pre = 0
            for j in range(1, n + 1):
                tmp = dp[j]
                dp[j] = max(dp[j - 1], dp[j], pre + (A[i - 1] == B[j - 1]))
                pre = tmp
        return dp[-1]
```

#### FASTEST
```
class Solution:
    def maxUncrossedLines(self, A, B) -> int:
        d = collections.defaultdict(list)
        for idx, val in reversed(list(enumerate((A)))):
            d[val].append(idx)
        dp = [0] * (len(A) + 1)
        for x in B:
            for j in d[x]:
                dp[j + 1] = max(dp[:j + 1]) + 1
        return max(dp)
```

```
class Solution:
    def maxUncrossedLines(self, A, B) -> int:
        d = collections.defaultdict(list)
        for i in range(len(B) - 1, -1, -1):
            d[B[i]].append(i)
        nums = []
        for x in A:
            if x in d:
                nums.extend(d[x])
        ans = []
        for x in nums:
            idx = bisect.bisect_left(ans, x)
            if idx == len(ans):
                ans.append(x)
            else:
                ans[idx] = x
        return len(ans)
```
