## Leetcode
#### Dynamic Programming
```
class Solution:
    def mctFromLeafValues(self, arr):
        n = len(arr)
        dp = [[0] * n for _ in range(n)]
        for j in range(n):
            for i in range(j - 1, -1, -1):
                if i + 1 == j:
                    dp[i][j] = arr[i] * arr[j]
                else:
                    ans = float('inf')
                    for k in range(i + 1, j + 1):
                        tmp = dp[i][k - 1] + dp[k][j] + max(arr[i:k]) * max(arr[k:j + 1])
                        if tmp < ans:
                            ans = tmp
                    dp[i][j] = ans
        return dp[0][-1] 
```

```
class Solution:
    def mctFromLeafValues(self, A):
        res, n = 0, len(A)
        stack = [float('inf')]
        for a in A:
            while stack[-1] <= a:
                mid = stack.pop()
                res += mid * min(stack[-1], a)
            stack.append(a)
        while len(stack)  >2:
            res += stack.pop() * stack[-1]
        return res
```
                
            
