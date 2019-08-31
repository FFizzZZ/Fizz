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

#### FASTEST
```
class Solution:
    def mctFromLeafValues(self, arr):
        stack = [float('inf')]
        ans = 0
        for x in arr:
            while stack[-1] <= x:
                smaller = stack.pop()
                ans += smaller * min(stack[-1], x)
            stack.append(x)
        n = len(stack)
        while n > 2:
            n -= 1
            smaller = stack.pop()
            ans += smaller * stack[-1]
        return ans
```
                
            
