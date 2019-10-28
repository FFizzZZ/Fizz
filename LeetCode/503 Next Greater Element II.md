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

```
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        if not nums: return []
        stack = []
        ans = [float("inf")] * len(nums)
        for idx, val in enumerate(nums):
            while stack and nums[stack[-1]] < val:
                ans[stack.pop()] = val
            stack.append(idx)
        Max = max(nums)
        while nums[stack[-1]] < Max:
            i = stack.pop()
            for j in range(i):
                if nums[j] > nums[i]:
                    ans[i] = nums[j]
                    break
        for i in stack:
            ans[i] = -1
        return ans
```
