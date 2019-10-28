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
    def nextGreaterElements(self, arr: List[int]) -> List[int]:
        stack = arr[::-1]
        for i in range(len(arr)-1, -1, -1):
            tmp = arr[i]
            while stack and stack[-1] <= arr[i]:
                stack.pop()
            if stack:
                arr[i] = stack[-1]
            else:
                arr[i] = -1
            stack.append(tmp)
        return arr
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
