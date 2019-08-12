## Leetcode
#### Permutations TLE
```
class Solution(object):
    def reorderedPowerOf2(self, N):
        return any(cand[0] != '0' and bin(int("".join(cand))).count('1') == 1
                   for cand in itertools.permutations(str(N)))
```

#### Counting
```
class Solution(object):
    def reorderedPowerOf2(self, N):
        count = collections.Counter(str(N))
        return any(count == collections.Counter(str(1 << b)) for b in range(31))
```
