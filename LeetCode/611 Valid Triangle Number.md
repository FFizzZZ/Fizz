## Leetcode
#### BinarySearch
```
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        n = len(nums)
        for i in range(n - 2):
            k = i + 2
            if nums[i] == 0: continue
            for j in range(i + 1, n - 1):
                k = bisect.bisect_left(nums, nums[i] + nums[j], k, n)
                ans += k - j - 1
        return ans
```

####
```
class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        n = len(nums)
        for i in range(n - 1, 1, -1):
            l, r = 0, i - 1
            while l < r:
                if nums[l] + nums[r] > nums[i]:
                    ans += r - l
                    r -= 1
                else:
                    l += 1
        return ans
```
