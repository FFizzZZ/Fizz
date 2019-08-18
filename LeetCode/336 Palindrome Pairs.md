## Leetcode
```
class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        ans = []
        rev = {s[::-1]: i for i, s in enumerate(words)}

        for i, s in enumerate(words):
            if s:
                for j in range(len(s)):
                    l, r = s[:j], s[j:]

                    if l in rev and i != rev[l] and r == r[::-1]:
                        ans.append([i, rev[l]])

                    if r in rev and i != rev[r] and l == l[::-1]:
                        ans.append([rev[r], i])
            else:
                for j, t in enumerate(words):
                    if i != j and t == t[::-1]:
                        ans.append([i, j])

        return ans
```
