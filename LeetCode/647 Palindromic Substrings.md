## Leetcode
#### Expand Around Center
```
class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        ans = 0
        for center in range(2 * n - 1):            # for i in range(2*N-1):
            left = center // 2                     # left = i//2
            right = left + center % 2              # right = (i+1)//2
            while left >= 0 and right < n and s[left] == s[right]:
                ans += 1
                left -= 1
                right += 1
        return ans
```

```
class Solution:
    def countSubstrings(self, S):
        count = 0
        for i in range(len(S)):
            count += self.f(i, i, S)
            count += self.f(i, i + 1, S)
        return count
    def f(self, l, r, s):
        n = len(s)
        count = 0
        while l >= 0 and r < n and s[l] == s[r]:
            count += 1
            l -= 1
            r += 1
        return count
```

#### Manacher's Algorithm
```
class Solution:
    def countSubstrings(self, S):
        def manachers(S):
            A = '@#' + '#'.join(S) + '#$'
            Z = [0] * len(A)
            center = right = 0
            for i in range(1, len(A) - 1):
                if i < right:
                    Z[i] = min(right - i, Z[2 * center - i])
                while A[i + Z[i] + 1] == A[i - Z[i] - 1]:
                    Z[i] += 1
                if i + Z[i] > right:
                    center, right = i, i + Z[i]
            return Z

        return sum((v+1) // 2 for v in manachers(S))
```
