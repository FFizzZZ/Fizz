```
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        stack = []
        n = len(nums)
        ans = [-1] * n
        for idx, val in enumerate(nums * 2):
            while stack and nums[stack[-1]] < val:
                ans[stack.pop()] = val
            if idx < n:
                stack.append(idx)
        return ans
```


## Leetcode
```
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        stack = nums[::-1]
        n = len(nums)
        ans = [-1] * n
        for i in range(n - 1, -1, -1):
            val = nums[i]
            while stack and stack[-1] <= val:
                stack.pop()
            if stack:
                ans[i] = stack[-1]
            stack.append(val)
        return ans
```
