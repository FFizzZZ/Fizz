## Leetcode
```
class Solution:
    def longestConsecutive(self, nums):
        ans = 0
        d = {}
        for i in nums:
            if i not in d:
                left = d[i - 1] if i - 1 in d else 0
                right = d[i + 1] if i + 1 in d else 0
                s = left + right + 1
                d[i] = s
                if s > ans:
                    ans = s
                d[i - left] = s
                d[i + right] = s
        return ans
```

#### Sorting
```
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums: return 0
        nums.sort()
        ans = 1
        temp = 1
        for i in range(1, len(nums)):
            if nums[i] != nums[i - 1]:
                if nums[i] == nums[i - 1] + 1:
                    temp += 1
                else:
                    if temp > ans:
                        ans = temp
                    temp = 1
        return temp if temp > ans else ans
```
#### HashSet and Intelligent Sequence Building
```
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        ans = 0
        for x in nums:
            if x - 1 not in s:
                tmp = x + 1
                while tmp in s:
                    tmp += 1
                ans = max(ans, tmp - x)
        return ans
```

