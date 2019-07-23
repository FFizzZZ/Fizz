## Leetcode
#### Brute Force TLE
```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        for _ in range(k):
            previous = nums[-1]
            for j in range(len(nums)):
                nums[j], previous = previous, nums[j]
```
#### Using Extra Space
```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        l = len(nums)
        new = [None] * l
        for i in range(l):
            new[(i + k) % l] = nums[i]
        for i in range(l):
            nums[i] = new[i]
```

#### Reverse
```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        l = len(nums)
        k %= l
        self.reverse(0, l - 1, nums)
        self.reverse(0, k - 1, nums)
        self.reverse(k, l - 1, nums)
    def reverse(self, l, r, nums):
        while l < r:
            nums[l], nums[r] = nums[r], nums[l]
            l += 1
            r -= 1
```
