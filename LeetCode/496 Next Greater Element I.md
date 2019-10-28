## Leetcode

#### Stack
```
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d = dict()
        stack = []
        for x in nums2:
            while stack and stack[-1] < x:
                d[stack.pop()] = x
            stack.append(x)
        ans = [0] * len(nums1)
        for idx, val in enumerate(nums1):
            ans[idx] = d.get(val, -1)
        return ans
```
