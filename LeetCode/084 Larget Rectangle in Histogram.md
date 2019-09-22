```
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights.append(0)
        stack = [-1]
        ans = 0
        for i, h in enumerate(heights):
            while heights[stack[-1]] > h:
                index = stack.pop()
                distance = i - stack[-1] - 1
                area = heights[index] * distance
                if area > ans: ans = area
            stack.append(i)
        return ans
```
## Leetcode
#### 计算每个柱子对应的最大长方形，l和r记录边界坐标
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
#### stack，与上一种方法思想类似
```
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        stack = []
        heights.append(0)      # An excellent operation that makes code more concise!!
        n = len(heights)       # we don't need to deal with the case where the stack is not empty after the loop.
        ans = 0
        for i in range(n):
            while stack and heights[stack[-1]] > heights[i]:
                x = stack.pop()
                if not stack:
                    distance = i
                else:
                    distance = i - stack[-1] - 1
                ans = max(ans, heights[x] * distance)
            stack.append(i)
        return ans
```
