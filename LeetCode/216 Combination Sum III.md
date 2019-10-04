```
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        self.helper(0, n, k, list(range(1, 10)), [], ans)
        return ans
    def helper(self, idx, target, k, nums, path, ans):
        if k == 0:
            if target == 0:
                ans.append(path[:])
            return
        for i in range(idx, len(nums) - k + 1):
            path.append(nums[i])
            self.helper(i + 1, target - nums[i], k - 1, nums, path, ans)
            path.pop()
```
