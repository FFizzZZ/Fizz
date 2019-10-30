## Leetcode


#### Stack
```
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 3: return False
        stack = []
        m = [0] * n
        m[0] = nums[0]
        for i in range(1, n):
            m[i] = min(m[i - 1], nums[i])
        for i in range(n - 1, - 1, -1):
            if nums[i] > m[i]:
                while stack and stack[-1] <= m[i]:
                    stack.pop()
                if stack and stack[-1] < nums[i]:
                    return True
                stack.append(nums[i])
        return False
```
