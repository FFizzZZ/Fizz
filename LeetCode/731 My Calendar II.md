## Leetcode
#### Brute Force
```
class MyCalendarTwo:
    def __init__(self):
        self.calendar = []
        self.overlaps = []

    def book(self, start: int, end: int) -> bool:
        for i, j in self.overlaps:
            if start < j and end > i:
                return False
        for i, j in self.calendar:
            if start < j and end > i:
                self.overlaps.append((max(start, i), min(end, j)))
        self.calendar.append((start, end))
        return True
```

#### Binary Search
```
class MyCalendarTwo:
    def __init__(self):
        self.one = []
        self.two = []

    def find(self, start, end):
        if end <= start: return -1
        i = bisect.bisect_right(self.two, start)
        if i % 2: return -1
        j = bisect.bisect_left(self.two, end)
        if i != j: return -1
        return i
              
    def book(self, start: int, end: int) -> bool:
        idx = self.find(start, end)
        if idx == -1: return False
        i = bisect.bisect_right(self.one, start)
        j = bisect.bisect_left(self.one, end)
        if i % 2:
            if j % 2:
                self.two[idx:idx] = [start] + self.one[i:j] + [end]
                self.one[i:j] = []
            else:
                self.two[idx:idx] = [start] + self.one[i:j]
                self.one[i:j] = [end]
        else:
            if j % 2:
                self.two[idx:idx] = self.one[i:j] + [end]
                self.one[i:j] = [start]
            else:
                self.two[idx:idx] = self.one[i:j]
                self.one[i:j] = [start, end]
        return True
```
