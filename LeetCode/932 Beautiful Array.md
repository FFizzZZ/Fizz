## Leetcode
```
class Solution:
    def beautifulArray(self, N):
        ans = [1]
        while len(ans) < N:
            ans = [2 * x - 1 for x in ans] + [2 * x for x in ans]
        return [x for x in ans if x <= N]
```
        
```
class Solution:
    def beautifulArray(self, N):
        memo = {1: [1]}
        def f(N):
            if N in memo: return memo[N]
            odds = f((N + 1) // 2)
            evens = f(N // 2)
            ans = [2 * x - 1 for x in odds] + [2 * x for x in evens]
            memo[N] = ans
            return ans
        return f(N)
```
        
```
class Solution:
    def beautifulArray(self, N):
        return sorted(range(1, N + 1), key=lambda x: bin(x)[:1:-1])
```
