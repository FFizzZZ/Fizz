## Leetcode
#### Locate and Analyze Problem Index
```
class Solution(object):
    def checkPossibility(self, A):
        p = None
        for i in range(len(A) - 1):
            if A[i] > A[i+1]:
                if p is not None:
                    return False
                p = i

        return (p is None or p == 0 or p == len(A)-2 or
                A[p-1] <= A[p+1] or A[p] <= A[p+2])
```

#### FASTEST
```
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        cnt = 0
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                cnt += 1
                if cnt > 1: return False
                if i == 0 or nums[i + 1] >= nums[i - 1]:
                    nums[i] = nums[i + 1]
                else:
                    nums[i + 1] = nums[i]
        return True
```
