```
class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        d1 = collections.Counter(A.split(' '))
        d2 = collections.Counter(B.split(' '))
        d = d1 + d2
        return [key for key, val in d.items() if val == 1]
```
## Leetcode
```
class Solution:
    def uncommonFromSentences(self, A: str, B: str) -> List[str]:
        d = collections.Counter((A + ' ' + B).split())
        return [key for key, val in d.items() if val == 1]
```
