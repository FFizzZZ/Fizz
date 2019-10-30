## Leetcode


#### Stack
```
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 3: return False
        stack = []
        m = [0] * n
        m[0] = nums[0]
        for i in range(1, n):
            m[i] = min(m[i - 1], nums[i])
        for i in range(n - 1, - 1, -1):
            if nums[i] > m[i]:
                while stack and stack[-1] <= m[i]:
                    stack.pop()
                if stack and stack[-1] < nums[i]:
                    return True
                stack.append(nums[i])
        return False
```

```
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        s3 = float('-inf')
        stack = []
        for i in range(len(nums) - 1, -1, -1):
            if nums[i] < s3:
                return True
            else:
                while stack and nums[i] > stack[-1]:
                    s3 = stack.pop()
                stack.append(nums[i])
        return False
```


#### FASTEST but NOT UNDERSTOOD
```
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        if len(nums) < 3: return False
        stck = []
        mi, mx = nums[0], nums[0]
        for n in nums[1:]:
            if n >= mx:
                mx = n
                while stck:
                    if n <= stck[-1][0]:
                        break
                    elif n < stck[-1][1]:
                        return True
                    else:
                        stck.pop()
            elif n > mi:
                return True
            else:
                stck.append((mi, mx))
                mi = mx = n
        return False
```

