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
#### Find the index of the rightmost element which is smaller than maximum on its left side.
```
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = -1, -2
        min, max = nums[n - 1], nums[0]
        for i in range(1, n):
            if nums[i] > max:
                max = nums[i]
            if nums[n - 1 - i] < min:
                min = nums[n - 1 - i]
            if nums[i] < max: r = i
            if nums[n - 1 - i] > min: l = n - 1 - i
        return r - l + 1
```
#### Without Using Extra Space. FASTEST!
```
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        left, right = n - 1, 0
        for i in range(n - 1):
            if nums[i] > nums[i+1]:
                left = i
                break
        for j in range(len(nums)-1,0,-1):
            if nums[j-1] > nums[j]:
                right = j
                break
        if left >= right: 
            return 0 
        minMid = min(nums[left:right+1])
        maxMid = max(nums[left:right+1])
        for left in range(n):
            if nums[left] > minMid:
                break
        for right in range(n - 1, -1, -1):
            if nums[right] < maxMid:
                break
        return right - left + 1 
```



        
        
        
        
        
        
        
