```
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = []
        for i in nums:
            index = abs(i) - 1
            if nums[index] < 0:
                ans.append(index + 1)
            else:
                nums[index] *= -1
        return ans
```

