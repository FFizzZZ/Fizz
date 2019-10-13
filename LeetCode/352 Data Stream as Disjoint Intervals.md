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
