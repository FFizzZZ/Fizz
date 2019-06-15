```
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = [[x] for x in nums]
        for x in nums:
            for i in range(len(ans)):
                if ans[i][-1] < x:
                    ans.append(ans[i] + [x])
        return ans + [[]]
```
