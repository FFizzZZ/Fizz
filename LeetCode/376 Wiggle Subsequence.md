## Leetcode

#### Dynamic Programming
```
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2: return n
        up = [1] * n
        down = [1] * n
        for j in range(1, n):
            for i in range(j):
                if nums[i] < nums[j]:
                    up[j] = max(up[j], down[i] + 1)
                elif nums[i] > nums[j]:
                    down[j] = max(down[j], up[i] + 1)
        return max(up[-1], down[-1])
```

#### O(n) Dynamic Programming
```
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2: return n
        up = [1] * n
        down = [1] * n
        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                up[i] = down[i - 1] + 1
                down[i] = down[i - 1]
            elif nums[i] < nums[i - 1]:
                down[i] = up[i - 1] + 1
                up[i] = up[i - 1]
            else:
                down[i] = down[i - 1]
                up[i] = up[i - 1]
        return max(up[-1], down[-1])
```


#### Greedy Approach
```
class Solution:
    def wiggleMaxLength(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2: return n
        pre = nums[1] - nums[0]
        cnt = 1 + (pre != 0)
        for i in range(2, n):
            diff = nums[i] - nums[i - 1]
            if diff > 0 and pre <= 0 or diff < 0 and pre >= 0:
                cnt += 1
                pre = diff
        return cnt
```
