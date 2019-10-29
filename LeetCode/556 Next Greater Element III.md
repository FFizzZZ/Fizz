## Leetcode

```
class Solution:
    def nextGreaterElement(self, n):
        s = list(str(n))
        i = len(s) - 1
        while i - 1 >= 0 and s[i] <= s[i - 1]:
            i -= 1
        if i == 0:
            return -1
        j = i
        while j + 1 < len(s) and s[j + 1] > s[i - 1]:
            j += 1
        s[i - 1], s[j] = s[j], s[i - 1]
        s[i:] = s[i:][::-1]
        ans = int("".join(s))
        return ans if ans <= 1 << 32 - 1 else -1
```

```
class Solution:
    def nextGreaterElement(self, n: int) -> int:
        nums = list(str(n))
        ans = float("inf")
        for i in range(len(nums) - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                for j in range(len(nums) - 1, i, -1):
                    if nums[j] > nums[i]:
                        nums[i], nums[j] = nums[j], nums[i]
                        break
                ans = int("".join(nums[:i + 1] + nums[i + 1:][::-1]))
                break
        return -1 if ans > 1 << 31 else ans
```
