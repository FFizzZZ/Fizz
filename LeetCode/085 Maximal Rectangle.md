## Leetcode
#### FASTEST ONE
```
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix: 
            return 0
        nums, area = [int(''.join(row), base=2) for row in matrix], 0
        for i in range(len(nums)):
            num = -1
            for j in range(i, len(nums)):
                num &= nums[j]
                if not num: 
                    break
                n, l = num, 0
                while n:
                    l += 1
                    n &= n << 1      # n &= n >> 1: this one is to calculate the longest continuous "1" subarray
                area = max(area, l * (j - i + 1))
        return area
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
                if matrix[i][j] == '1':
                    height[j] += 1
                else:
                    height[j] = 0
            stack = []
            for j in range(n + 1):
                while stack and height[j] < height[stack[-1]]:
                    h = height[stack.pop()]
                    if stack:
                        distance = j - 1 - stack[-1]
                    else:
                        distance = j
                    tmp = h * distance
                    if tmp > ans:
                        ans = tmp
                stack.append(j)
        return ans
```
##### This one has some tricks.
```
class Solution:
    def maximalRectangle(self, matrix):
        if not matrix or not matrix[0]:
            return 0
        n = len(matrix[0])
        height = [0] * (n + 1)  # !!!
        ans = 0
        for row in matrix:
            for i in range(n):
                height[i] = height[i] + 1 if row[i] == '1' else 0
            stack = [-1]        # !!!
            for i in range(n + 1):
                while height[i] < height[stack[-1]]:
                    h = height[stack.pop()]
                    w = i - 1 - stack[-1]
                    temp = h * w
                    if temp > ans:
                        ans = temp
                stack.append(i)
        return ans
```
