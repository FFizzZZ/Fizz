### Recurse
```
class Solution(object):
    def permute(self, nums):
        ans = []
        self.helper(nums, [], ans)
        return ans
        
    def helper(self, nums, path, ans):
        if not nums:
            ans.append(path[:])
        else:
            for i in range(len(nums)):
                path.append(nums[i])
                self.helper(nums[:i] + nums[i + 1:], path, ans)
                path.pop()
```        
### Iteration     
```
class Solution(object):
    def permute(self, nums):
        ans = [[]]
        for x in nums:
            tmp = []
            for y in ans:
                for i in range(len(y) + 1):
                    tmp.append(y[:i] + [x] + y[i:])
            ans = tmp
        return ans
```
