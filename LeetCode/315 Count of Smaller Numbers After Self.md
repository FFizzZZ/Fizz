```
class Solution:
    def countSmaller(self, nums):
        if not nums: return []
        ans = [0]
        num = [nums[-1]]
        for i in range(len(nums) - 2, -1, -1):
            index = self.find(num, nums[i])
            ans.append(index)
            num.insert(index, nums[i])
        return ans[::-1]
    def find(self, num, target):
        l, r = 0, len(num) - 1
        if target < num[0]: return 0
        if target > num[-1]: return r + 1
        while l < r:
            mid = (l + r) // 2
            val = num[mid]
            if val < target:
                l = mid + 1
            else:
                r = mid
        return l
```

## Leetcode
#### FASTEST
```
class Solution:
    def countSmaller(self, nums):
        if not nums: return []
        stk = []
        ans = []
        for x in reversed(nums):
            idx = bisect.bisect_left(stk, x)
            ans.append(idx)
            stk[idx:idx] = [x]
        return ans[::-1]
```

#### MergeSort
```
class Solution:
    def countSmaller(self, nums):
        ans = [0] * len(nums)
        self.f(list(enumerate(nums)), ans)
        return ans
    def f(self, nums, ans):
        n = len(nums)
        if n <= 1:
            return nums
        mid = n // 2
        left, right = self.f(nums[:mid], ans), self.f(nums[mid:], ans)
        for i in range(n - 1, -1, -1):
            if not right or left and left[-1][1] > right[-1][1]:
                ans[left[-1][0]] += len(right)
                nums[i] = left.pop()
            else:
                nums[i] = right.pop()
        return nums
```
#### Binary Indexed Tree
```
class Solution:
    def countSmaller(self, nums):
        rank = {val: i + 1 for i, val in enumerate(sorted(nums))}
        n = len(nums)
        BIT = [0] * (n + 1)
        
        def update(i):
            while i <= n:
                BIT[i] += 1
                i += i & (-i)
        def get(i):
            s = 0
            while i > 0:
                s += BIT[i]
                i -= i & (-i)
            return s
        
        ans = []
        for x in reversed(nums):
            update(rank[x])
            ans += get(rank[x] - 1),
        return ans[::-1]
```







