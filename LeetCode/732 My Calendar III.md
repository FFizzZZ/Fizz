## Leetcode
#### Boundary Count
```
class MyCalendarThree:
    def __init__(self):
        self.times = []

    def book(self, start: int, end: int) -> int:
        bisect.insort(self.times, (start, 1))
        bisect.insort(self.times, (end, -1))
        active = ans = 0
        for _, val in self.times:
            active += val
            if active > ans: ans = active
        return ans
```

```
class MyCalendarThree(object):
    def __init__(self):
        self.data = [[sys.maxsize, 0], [sys.maxsize, 0]]
        self.k = 0
    
    def book(self, start, end):
        d = self.data
        i = bisect.bisect_left(self.data, [start, 0])
        if d[i][0] > start:
            d.insert(i, [start, d[i - 1][1]])
        while d[i][0] < end:
            d[i][1] += 1
            self.k = max(self.k, d[i][1])
            i += 1
        if d[i][0] > end:
            d.insert(i, [end, d[i - 1][1] - 1])
        return self.k 
```

```
class MyCalendarThree:
    def __init__(self):
        self.X = [-1, int(1e9)]
        self.track = [0, 0]
        self.K = 0

    def book(self, start: int, end: int) -> int:
        def index(t):
            i = bisect.bisect_left(self.X, t)
            if self.X[i] != t:
                self.X.insert(i, t)
                self.track.insert(i, self.track[i - 1])
            return i
        i, j = index(start), index(end)
        self.track[i:j] = [k + 1 for k in self.track[i:j]]
        self.K = max(self.K, max(self.track[i:j]))
        return self.K
```
