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
