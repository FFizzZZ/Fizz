## Leetcode
#### Random Pick
```
class MajorityChecker:
    def __init__(self, arr: List[int]):
        d = collections.defaultdict(list)
        for idx, val in enumerate(arr):
            d[val].append(idx)
        self.array = arr
        self.d = d

    def query(self, left: int, right: int, threshold: int) -> int:
        for _ in range(10):
            idx = self.array[random.randint(left, right)]
            l = bisect.bisect_left(self.d[idx], left)
            r = bisect.bisect_right(self.d[idx], right)
            if r - l >= threshold:
                return idx
        return -1
```
