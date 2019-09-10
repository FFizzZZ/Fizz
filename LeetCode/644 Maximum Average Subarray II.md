## Leetcode
#### Binary Search
```
class Solution:
  def findMaxAverage(self, nums, k):
    l, r = min(nums), max(nums)
    while r - l > 0.00001:
      mid = (l + r) / 2
      if self.check(nums, mid, k):
        l = mid
      else:
        r = mid
    return l
  def check(self, nums, mid, k):
    cur = 0
    pre = 0
    min_sum = 0
    for i in range(k):
      cur += nums[i] - mid
    if cur >= 0:
      return True
    for i in range(k, len(nums)):
      cur += nums[i] - mid
      pre += nums[i - k] - mid
      min_sum = min(pre, min_sum)
      if cur >= min_sum:
        return True
    return False
```
  
  
  
  
  
  
