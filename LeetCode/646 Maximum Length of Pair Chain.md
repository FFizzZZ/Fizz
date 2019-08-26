## Leetcode
#### Dynamic Programming
```
class Solution(object):
    def findLongestChain(self, pairs):
        pairs.sort()
        n = len(pairs)
        dp = [1] * n
        for j in range(n):
            for i in range(j):
                if pairs[i][1] < pairs[j][0]:
                    dp[j] = max(dp[j], dp[i] + 1)
        return max(dp)
```

#### Greedy
```
class Solution(object):
    def findLongestChain(self, pairs):
        cur = float('-inf')
        cnt = 0
        for x, y in sorted(pairs, key = operator.itemgetter(1)):
            if cur < x:
                cur = y
                cnt += 1
        return cnt
```
