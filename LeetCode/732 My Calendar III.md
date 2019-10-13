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
#### FASTEST
```
class MyCalendarThree:
    def __init__(self):
        self.time = [[-sys.maxsize, 0], [sys.maxsize, 0]]
        self.ans = 0

    def book(self, start: int, end: int) -> int:
        idx = bisect.bisect_left(self.time, [start, 0])
        if self.time[idx][0] > start:
            self.time.insert(idx, [start, self.time[idx - 1][1]])
        while self.time[idx][0] < end:
            self.time[idx][1] += 1
            self.ans = max(self.ans, self.time[idx][1])
            idx += 1
        if self.time[idx][0] > end:
            self.time.insert(idx, [end, self.time[idx - 1][1] - 1])
        return self.ans
```
