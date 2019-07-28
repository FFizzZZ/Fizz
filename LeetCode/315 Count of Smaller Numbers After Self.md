## Leetcode
```
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        if not nums:
            return 
        res = [0]
        sortednums = [nums[-1]]
        for i in range(len(nums) - 2, -1, -1):
            idx = bisect.bisect_left(sortednums, nums[i])
            res.append(idx)
            sortednums.insert(idx, nums[i])
        return reversed(res)
```
