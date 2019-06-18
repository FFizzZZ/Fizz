```
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        self.f(nums, [], ans)
        return ans
    def f(self, nums, path, ans):
        if not nums:
            ans.append(path[:])
        else:
            for i in range(len(nums)):
                if i > 0 and nums[i] == nums[i - 1]:
                    continue
                else:
                    path.append(nums[i])
                    self.f(nums[:i] + nums[i+1:], path, ans)
                    path.pop()
```
------------------------------

class Solution:
    def permuteUnique(self, nums):
        ans = [[]]
        for n in nums:
            new_ans = []
            for l in ans:
                for i in range(len(l)+1):
                    new_ans.append(l[:i]+[n]+l[i:])
                    if i<len(l) and l[i]==n: break     #handles duplication
            ans = new_ans
        return ans
