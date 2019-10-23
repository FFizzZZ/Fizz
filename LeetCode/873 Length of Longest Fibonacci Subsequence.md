## Leetcode
```
class Solution:
    def lenLongestFibSubseq(self, A: List[int]) -> int:
        d = {x: i for i, x in enumerate(A)}
        dp = collections.defaultdict(lambda: 2)
        ans = 0
        for k, z in enumerate(A):
            for j in range(k):
                i = d.get(z - A[j], None)
                if i is not None and i < j:
                    tmp = dp[j, k] = dp[i, j] + 1
                    if tmp > ans: ans = tmp
        return ans if ans > 2 else 0
```
    
