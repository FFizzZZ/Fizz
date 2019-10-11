## Leetcode
#### Boundary Count
##### I think this method is exactly the same as the one calculating the most number online in a period of time.
```
class MyCalendarThree:
    def __init__(self):
        self.delta = collections.defaultdict(int)

    def book(self, start: int, end: int) -> int:
        self.delta[start] += 1
        self.delta[end] -= 1
        active = ans = 0
        for x in sorted(self.delta):
            active += self.delta[x]
            if active > ans: ans = active
        return ans
```
##### Same idea yet Faster
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
