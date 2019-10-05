## Leetcode
#### BinarySearch
```
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        n = len(nums)
        for i in range(n - 2):
            if nums[i] == 0: continue
            for j in range(i + 1, n - 1):
                idx = self.search(nums, j + 1, n, nums[i] + nums[j])
                ans += idx - j - 1
        return ans
    def search(self, nums, l, r, target):
        while l < r:
            mid = (l + r) // 2
            if nums[mid] >= target:
                r = mid
            else:
                l = mid + 1
        return l
```
