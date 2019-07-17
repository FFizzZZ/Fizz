## Leetcode
#### Using Sorting
```
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        num = nums.copy()
        num.sort()
        n = len(nums)
        l, r = n, 0
        for i in range(n):
            if num[i] != nums[i]:
                if i < l:
                    l = i
                if i > r:
                    r = i
        return 0 if l == n else r - l + 1
```

#### Using Stack
```
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        stack = []
        n = len(nums)
        l, r = n, 0
        for i in range(n):
            while stack and nums[stack[-1]] > nums[i]:
                temp = stack.pop()
                if temp < l:
                    l = temp
            stack.append(i)
        stack = []
        for i in range(n - 1, -1, -1):
            while stack and nums[stack[-1]] < nums[i]:
                temp = stack.pop()
                if temp > r:
                    r = temp
            stack.append(i)
        return r - l + 1 if r != 0 else 0
```

#### Without Using Extra Space
```
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        min, max = float('inf'), float('-inf')
        flag = False
        n = len(nums)
        if n == 1: return 0
        for i in range(1, n):
            if nums[i] < nums[i - 1]:
                break
        for j in range(i, n):
            if nums[j] < min:
                min = nums[j]
        for i in range(n - 2, -1, -1):
            if nums[i] > nums[i + 1]:
                break
        for j in range(i, -1, -1):
            if nums[j] > max:
                max = nums[j]
        for l in range(n):
            if nums[l] > min:
                break
        for r in range(n - 1, -1, -1):
            if nums[r] < max:
                break
        return 0 if r - l < 0 else r - l + 1
```
