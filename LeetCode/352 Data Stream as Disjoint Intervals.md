## Leetcode
```
class SummaryRanges(object):
    def __init__(self):
        self.intervals = []

    def addNum(self, val):
        l, r = 0, len(self.intervals) - 1
        while l <= r:
            mid = (l + r) // 2
            interval = self.intervals[mid]
            if interval[0] <= val <= interval[1]:
                return
            elif interval[0] > val:
                r = mid - 1
            else:
                l = mid + 1
        idx = l
        self.intervals.insert(idx, [val, val])
        if idx + 1 < len(self.intervals) and val == self.intervals[idx + 1][0] - 1:
            self.intervals[idx][1] = self.intervals[idx + 1][1]
            self.intervals[idx + 1:idx + 2] = []
        if idx - 1 >= 0 and val == self.intervals[idx - 1][1] + 1:
            self.intervals[idx - 1][1] = self.intervals[idx][1]
            self.intervals[idx:idx + 1] = []
            
    def getIntervals(self):
        return self.intervals
```

```
class SummaryRanges:
    def __init__(self):
        self.start = {}
        self.end = {}
        self.visited = set()

    def addNum(self, val: int) -> None:
        if val in self.visited: return
        self.visited.add(val)
        start, end = val, val
        if val + 1 in self.start:
            end = self.start[val + 1]
            self.start.pop(val + 1)
        if val - 1 in self.end:
            start = self.end[val - 1]
            self.end.pop(val - 1)
        self.start[start] = end
        self.end[end] = start
        
    def getIntervals(self) -> List[List[int]]:
        return [[start, end] for start, end in sorted(self.start.items())]
```
