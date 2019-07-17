```
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        count = 0
        for i in S:
            if i in J:
                count += 1
        return count
```

## Leetcode
```
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        return sum(map(J.count, S))
```

```
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        return sum(map(S.count, J))
```
