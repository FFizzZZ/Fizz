```
class Solution:
    def trap(self, height: List[int]) -> int:
        m = 0
        n = len(height)
        l, r = 0, n - 1
        cnt = 0
        while l <= r:
            if height[l] < height[r]:
                if height[l] < m:
                    cnt += m - height[l]
                else:
                    m = height[l]
                l += 1
            else:
                if height[r] < m:
                    cnt += m - height[r]
                else:
                    m = height[r]
                r -= 1
        return cnt
```
## Leetcode
#### dynamic programming for leftmax and rightmax
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

#### stack
```
class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0; stack = []
        for cur in range(len(height)):
            while stack and height[stack[-1]] < height[cur]:
                top = stack.pop()
                if not stack:
                    break
                distance = cur - stack[-1] - 1
                h = min(height[cur], height[stack[-1]]) - height[top]
                ans += h * distance
            stack.append(cur)
        return ans
```

#### two pointers
```
class Solution:
    def trap(self, height: List[int]) -> int:
        l, r = 0, len(height) - 1
        ans = 0
        lmax, rmax = 0, 0
        while l < r:
            if height[l] < height[r]:
                if height[l] >= lmax:
                    lmax = height[l]
                else:
                    ans += lmax - height[l]
                l += 1
            else:
                if height[r] > rmax:
                    rmax = height[r]
                else:
                    ans += rmax - height[r]
                r -= 1
        return ans
```
