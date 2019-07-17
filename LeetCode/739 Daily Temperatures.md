```
class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        n = len(T)
        ans = [0] * n
        stack = []
        for i in range(n):
            while stack and T[stack[-1]] < T[i]:
                index = stack.pop()
                ans[index] = i - index
            stack.append(i)
        return ans
```
