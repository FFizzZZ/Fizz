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

```
class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = []
        for i in range(n):
            while nums[i] != nums[nums[i] - 1]:
                tmp = nums[i]
                nums[i] = nums[tmp - 1]
                nums[tmp - 1] = tmp
        for i in range(n):
            if nums[i] != i + 1:
                ans.append(nums[i])
        return ans
```
