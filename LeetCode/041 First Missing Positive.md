```
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums = [n for n in nums if n > 0]
        for i in range(1, len(nums)+1):
            if i not in nums:
                return i
        return len(nums) + 1
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
-------------------
```
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums = [n for n in nums if n > 0]
        n = len(nums)
        for i in range(n):
            ind = abs(nums[i])-1
            if ind < n and nums[ind] > 0:
                nums[ind] = - nums[ind]
        for i in range(n):
            if nums[i]>0:
                return i + 1
        return n + 1
```
