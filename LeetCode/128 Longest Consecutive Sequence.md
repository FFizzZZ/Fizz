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

```
class Solution:
    def longestConsecutive(self, nums):
        longest_streak = 0
        num_set = set(nums)

        for num in num_set:
            if num - 1 not in num_set:
                current_num = num
                current_streak = 1

                while current_num + 1 in num_set:
                    current_num += 1
                    current_streak += 1
                longest_streak = max(longest_streak, current_streak)

        return longest_streak
```

