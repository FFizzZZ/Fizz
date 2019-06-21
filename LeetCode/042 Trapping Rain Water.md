## dynamic programming for leftmax and rightmax
```
class Solution:
    def trap(self, height: List[int]) -> int:
        if not height: return 0
        ans = 0
        n = len(height)
        l, r = [0] * n, [0] * n
        l[0], r[n - 1] = height[0], height[n - 1]
        for i in range(1, n - 1):
            l[i] = max(l[i - 1], height[i])
        for i in range(n - 2, 0, -1):
            r[i] = max(r[i + 1], height[i])
        for i in range(1, n - 1):
            ans += min(l[i], r[i]) - height[i]
        return ans
```

## stack
```
class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0; cur = 0; stack = []
        while cur < len(height):
            while stack and height[stack[-1]] < height[cur]:
                top = stack.pop()
                if not stack:
                    break
                distance = cur - stack[-1] - 1
                h = min(height[cur], height[stack[-1]]) - height[top]
                ans += h * distance
            stack.append(cur)
            cur += 1
        return ans
```
