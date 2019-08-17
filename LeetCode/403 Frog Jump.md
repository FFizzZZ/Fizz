```
class Solution:
    def canCross(self, stones: List[int]) -> bool:
        return self.f(1, 1, stones, {}) if stones[1] == 1 else False
    def f(self, index, k, stones, d):
        if (index, k) in d: return d[(index, k)]
        n = len(stones)
        if index == n - 1:
            return True
        val = stones[index]
        ans = False
        for i in range(index + 1, n):
            tmp = stones[i] - val
            if tmp in [k - 1, k, k + 1] and self.f(i, tmp, stones, d):
                ans = True
                break
        d[(index, k)] = ans
        return ans
```

## Leetcode
```
class Solution:
    def canCross(self, s: List[int]) -> bool:
        stones = set(s)
        step = 1
        for i in range(len(s) - 1):
            if s[i + 1] - s[i] > step: return False
            step += 1
        def helper(start, end, step):
            if start == end: return True
            if start not in stones: return False
            if helper(start + step + 1, end, step + 1): return True
            if helper(start + step, end, step): return True
            if step > 1 and helper(start + step - 1, end, step - 1): return True
            return False
        return helper(1, s[-1], 1)
```
