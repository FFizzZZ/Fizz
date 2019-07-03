### Recurse
```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        self.f(nums, [], ans)
        return ans
    def f(self, nums, path, ans):
        if not nums:
            ans.append(path[:])
        else:
            for i in range(len(nums)):
                path.append(nums[i])
                self.f(nums[:i] + nums[i + 1:], path, ans)
                path.pop()
```        
### Iteration     
```
class Solution(object):
    def permute(self, nums):
        res = [[]]
        for i in nums:
            new = []
            for j in res:
                for k in range(len(j)+1):
                    new.append(j[:k]+[i]+j[k:])
            res = new
        return res
```
