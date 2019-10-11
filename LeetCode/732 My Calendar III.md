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
