```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        k %= n
        nums[:] = nums[n - k:] + nums[:n - k]
```

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
#### Using Cyclic Replacements
```
class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        n = len(nums)
        k %= n
        count = 0
        for start in range(n):
            if count < n:
                current = start
                prev = nums[start]
                next = (current + k) % n
                nums[next], prev = prev, nums[next]
                count += 1
                current = next
                while start != current:
                    next = (current + k) % n
                    nums[next], prev = prev, nums[next]
                    count += 1
                    current = next  
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
