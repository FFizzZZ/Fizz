## 计算每个柱子对应的最大长方形，l和r记录边界坐标
```
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        if not heights: return 0
        n = len(heights)
        l, r = [0] * n, [0] * n
        l[0], r[n - 1] = -1, n
        for i in range(1, n):
            x = i - 1
            while x > -1 and heights[x] >= heights[i]:
                x = l[x]
            l[i] = x
        for i in range(n - 2, -1, -1):
            x = i + 1
            while x < n and heights[x] >= heights[i]:
                x = r[x]
            r[i] = x
        ans = 0
        for i in range(n):
            ans = max(ans, heights[i] * (r[i] - l[i] - 1))
        return ans
```
