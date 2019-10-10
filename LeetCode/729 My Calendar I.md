## Leetcode

#### Brute Force
```
class MyCalendar:
    def __init__(self):
        self.calendar = []

    def book(self, start: int, end: int) -> bool:
        for s, e in self.calendar:
            if s < end and e > start:
                return False
        self.calendar.append((start, end))
        return True
```

#### Binary Search
```
class MyCalendar:    
    def __init__(self):
        self.intervals = [[-2, -1], [10 ** 9 + 1, 10 ** 9 + 2]]        

    def book(self, start: int, end: int) -> bool:
        curr = [start, end]
        index = bisect.bisect_left(self.intervals, curr)
        if(self.intervals[index - 1][1] > start or self.intervals[index][0] < end):
            return False
        self.intervals.insert(index, curr)
        return True
```

```
class MyCalendar:    
    def __init__(self):
        self.intervals = []      

    def book(self, start: int, end: int) -> bool:
        idx_right = bisect.bisect_right(self.intervals, start)
        if idx_right % 2:  # try to insert to the middle of a booking
            return False
        idx_left = bisect.bisect_left(self.intervals, end)
        if idx_left != idx_right:
            return False
        self.intervals[idx_right:idx_right] = [start, end]
        return True
```
