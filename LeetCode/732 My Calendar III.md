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
        self.times = [[-sys.maxsize, 0], [sys.maxsize, 0]]
        self.ans = 0

    def book(self, start: int, end: int) -> int:
        times = self.times
        idx = bisect.bisect_left(times, [start, 0])
        if times[idx][0] > start:
            times.insert(idx, [start, times[idx - 1][1]])
        while times[idx][0] < end:
            times[idx][1] += 1
            if times[idx][1] > self.ans: self.ans = times[idx][1]
            idx += 1
        if times[idx][0] > end:
            times.insert(idx, [end, times[idx - 1][1] - 1])
        return self.ans
```
