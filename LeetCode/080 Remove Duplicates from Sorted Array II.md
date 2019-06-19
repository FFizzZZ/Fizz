```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums: return 0
        i = 0
        count = 2
        temp = nums[0]
        while i < len(nums):
            if nums[i] == temp:
                if count == 0:
                    del nums[i]
                else:
                    count -= 1
                    i += 1
            else:
                temp = nums[i]
                count = 1
                i += 1
        return len(nums)
```

## leetcode
```
class Solution:
    def removeDuplicates(self, nums):
        i = 0
        for n in nums:
            if i < 2 or n > nums[i-2]:
                nums[i] = n
                i += 1
        return i
```
