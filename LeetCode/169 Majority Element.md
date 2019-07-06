```
class Solution(object):
    def majorityElement(self, nums):
        ans = nums[0]
        count = 0
        for x in nums:
            if ans == x:
                count += 1
            else:
                count -= 1
            if count == 0:
                ans = x
                count = 1
        return ans
```

## Leetcode
#### HashMap
```

class Solution(object):
    def majorityElement(self, nums):
        counts = collections.Counter(nums)
        return max(counts.keys(), key = counts.get)
```

#### Sorting
```
class Solution(object):
    def majorityElement(self, nums):
        nums.sort()
        return nums[len(nums) // 2]
```

#### Boyer-Moore Voting Algorithm
```
class Solution(object):
    def majorityElement(self, nums):
        count = 0
        candidate = None
        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)
        return candidate
```
