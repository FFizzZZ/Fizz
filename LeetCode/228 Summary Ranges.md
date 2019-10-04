```
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums: return []
        ans = []
        start = nums[0]
        nums.append(nums[-1])
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1] + 1:
                if nums[i - 1] == start:
                    ans.append(str(start))
                else:
                    string = str(start) + "->" + str(nums[i - 1])
                    ans.append(string)
                start = nums[i]
        return ans
```
