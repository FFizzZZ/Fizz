```
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums = [n for n in nums if n > 0]
        for i in range(1, len(nums)+1):
            if i not in nums:
                return i
        return len(nums) + 1
```
#### mark the visited element's corresponding index as negative
```
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums = [x for x in nums if x > 0]
        n = len(nums)
        for i in nums:
            index = abs(i) - 1
            if index < n and nums[index] > 0:
                nums[index] *= -1
        for i in range(n):
            if nums[i] > 0:
                return i + 1
        return n + 1
```
#### add n + 1 to the visited index
```
class Solution:
    def firstMissingPositive(self, nums):
        n = len(nums)
        for i in range(n):
            if nums[i] < 1 or nums[i] >= n + 1:
                nums[i] = 0
        for i in range(n):
            if nums[i] % (n + 1) != 0:
                nums[nums[i] % (n + 1) - 1] += n + 1
        for i in range(n):
            if nums[i] <= n:
                return i + 1
        return n + 1
```
## Leetcode
#### swap elements in-place
```
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while nums[i] > 0 and nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                temp = nums[i]
                nums[i] = nums[temp - 1]
                nums[temp - 1] = temp
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        return n + 1
```
#### append 0, really amazing!
```
class Solution:
    def firstMissingPositive(self, nums):
        nums.append(0)
        n = len(nums)
        for i in range(len(nums)): #delete those useless elements
            if nums[i] < 0 or nums[i] >= n:
                nums[i]=0
        for i in range(len(nums)):
            nums[nums[i] % n] += n
        for i in range(1,len(nums)):
            if nums[i] < n:
                return i
        return n
```


```
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.sort()
        index = sum([i <= 0 for i in nums])
        temp = []
        for i in nums[index:]:
            if i not in temp:
                temp.append(i)
        res = [i + 1 - j for i, j in enumerate(temp)]
        if any(res):
            return [i != 0 for i in res].index(1) + 1
        else:
            return len(res) + 1
```

