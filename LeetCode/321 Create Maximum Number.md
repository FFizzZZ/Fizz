## Leetcode
#### The merge function is really amazing, which is somewhat differenet from the usual one.
```
class Solution:
    def maxNumber(self, nums1, nums2, k):
        n1, n2 = len(nums1), len(nums2)
        return max(self.merge(self.cut(nums1, i), self.cut(nums2, k - i))
                  for i in range(k + 1)
                  if i <= n1 and k - i <= n2)
    
    def cut(self, nums, k):
        drop = len(nums) - k
        stack = []
        for x in nums:
            while drop and stack and stack[-1] < x:
                stack.pop()
                drop -= 1
            stack.append(x)
        return stack[:k]
    
    def merge(self, a, b):
        return [max(a, b).pop(0) for _ in a + b]
```
