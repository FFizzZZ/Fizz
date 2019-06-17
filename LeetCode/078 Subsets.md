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

## leetcode
Iterative
```
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = [[]]
        for x in nums:
            for i in range(len(ans)):
                ans.append(ans[i] + [x])
        return ans
```
Recursive (Backtracking)
```
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        self.f(0, nums, [], ans)
        return ans
    def f(self, start, nums, path, ans):
        ans.append(path[:])
        for i in range(start, len(nums)):
            path.append(nums[i])
            self.f(i + 1, nums, path, ans)
            path.pop()
```

bit manipulation
```
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        p =  1 << n
        ans = [[] for _ in range(p)]
        for i in range(p):
            for j in range(n):
                if (i >> j) & 1:
                    ans[i].append(nums[j])
        return ans
```
