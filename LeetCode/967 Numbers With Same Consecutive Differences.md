```
class Solution:
    def numsSameConsecDiff(self, N, K):
        if N == 1: return list(range(10))
        ans = {x for x in range(1, 10)}
        for _ in range(N - 1):
            tmp = set()
            for x in ans:
                d = x % 10
                if d + K < 10:
                    tmp.add(10 * x + d + K)
                if d - K > -1:
                    tmp.add(10 * x + d - K)
            ans = tmp
        return list(ans)
```
