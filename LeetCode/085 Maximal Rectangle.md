## Leetcode
#### FASTEST ONE
```
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix: return 0
        nums = [int("".join(row), base = 2) for row in matrix]
        ans = 0
        for i in range(len(matrix)):
            cur = -1
            for j in range(i, len(matrix)):
                cur &= nums[j]
                if cur == 0:
                    break
                n = cur
                l = 0
                while n:
                    l += 1
                    n &= n >> 1
                area = l * (j - i + 1)
                if area > ans: ans = area
        return ans
```

#### Dynamic Programming
```
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix: return 0
        m, n = len(matrix), len(matrix[0])
        left, right, height = [0] * n, [n] * n, [0] * n
        ans = 0
        for i in range(m):
            l, r = 0, n
            for j in range(n - 1, -1, -1):
                if matrix[i][j] == '1':
                    right[j] = min(right[j], r)
                else:
                    right[j] = n
                    r = j
            for j in range(n):
                if matrix[i][j] == '1': 
                    height[j] += 1
                    left[j] = max(left[j], l)
                    temp = (right[j] - left[j]) * height[j]
                    if temp > ans:
                        ans = temp
                else:
                    height[j] = 0
                    left[j] = 0
                    l = j + 1
        return ans
```

#### Stack
```
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix: return 0
        m, n = len(matrix), len(matrix[0])
        height = [0] * (n + 1)
        ans = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == "1":
                    height[j] += 1
                else:
                    height[j] = 0
            stack = [-1]
            for j, h in enumerate(height):
                while height[stack[-1]] > h:
                    index = stack.pop()
                    distance = j - stack[-1] - 1
                    area = height[index] * distance
                    if area > ans: ans = area
                stack.append(j)
        return ans
```
