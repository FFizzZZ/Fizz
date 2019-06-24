## Iterative
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

## Recurse
```
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        self.f(0, nums, [], ans)
        return ans
    def f(self, index, nums, path, ans):
        ans.append(path[:])
        for i in range(index, len(nums)):
            if i > index and nums[i] == nums[i - 1]:
                continue
            path.append(nums[i])
            self.f(i + 1, nums, path, ans)
            path.pop()
```

## Bit manipulation
```
class Solution:
    def subsetsWithDup(self, nums):
        nums.sort()
        ans = []
        for i in range(2 ** len(nums)):
            temp = []
            res = 0
            for j in range(len(nums)):
                if i >> j & 1:
                    if j > 0 and nums[j] == nums[j - 1] and not i >> (j - 1) & 1:
                        res = 1
                        break
                    else:
                        temp.append(nums[j])
            if not res:
                ans.append(temp)
        return ans
```
