## Leetcode
```
class Solution:
    def tallestBillboard(self, rods: List[int]) -> int:
        rods.sort(reverse = True)
        for l in range(len(rods), 1, -1):
            for comb in itertools.combinations(rods, l):
                s = sum(comb)
                if s % 2 == 0:
                    s //= 2
                    X = set([s])
                    for x in comb:
                        if x in X:
                            return s
                        else:
                            Y = [y - x for y in X if y - x > 0]
                            X.update(Y)
        return 0
```
