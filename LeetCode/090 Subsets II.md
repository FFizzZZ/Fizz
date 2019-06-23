```
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = [[]]
        nums.sort()
        for i in range(len(nums)):
            if i > 0 and nums[i - 1] == nums[i]:
                ans += [ans[j] + [nums[i]] for j in range(len(ans) - temp, len(ans))]            
            else:
                temp = len(ans)
                ans += [j + [nums[i]] for j in ans]
        return ans
```
