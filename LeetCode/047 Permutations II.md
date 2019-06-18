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
```
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans = []
        self.f(nums, [], ans)
        return ans
    def f(self, nums, path, ans):
        if not nums:
            ans.append(path[:])
        else:
            for i in range(len(nums)):
                if nums[i] not in nums[:i]:
                    path.append(nums[i])
                    self.f(nums[:i] + nums[i+1:], path, ans)
                    path.pop()
```
------------------------------
```
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans = [[]]
        for i in nums:
            for _ in range(len(ans)):
                temp = ans.pop(0)
                for j in range(len(temp) + 1):
                    ans.append(temp[:j] + [i] + temp[j:])
                    if j < len(temp) and temp[j] == i: break     # handle duplication
        return ans
```
