```
class Solution:
    def insert(self, intervals, newInterval):
        s, e = newInterval[0], newInterval[1]
        left = [i for i in intervals if i[1] < s]
        right = [i for i in intervals if i[0] > e]
        if left + right != intervals:
            s = min(s, intervals[len(left)][0])
            e = max(e, intervals[~len(right)][1])
        return left + [[s, e]]+ right
```
```
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        s, e = newInterval
        parts = merge, left, right = [], [], []
        for i in intervals:
            parts[(i[1] < s) - (i[0] > e)].append(i)
        if merge:
            s = min(s, merge[0][0])
            e = max(e, merge[-1][1])
        return left + [[s, e]] + right
```

```
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        left, right = [], []
        l, r = newInterval
        for i in intervals:
            if i[1] < l:
                left.append(i)
            elif i[0] > r:
                right.append(i)
            else:
                l = min(l, i[0])
                r = max(r, i[1])
        return left + [[l, r]] + right
```

## too complicated, written by myself
```
class Solution:
    def insert(self, intervals, newInterval):
        if not intervals: return [newInterval]
        l, r = newInterval
        first, second = -1, -1
        for i in range(len(intervals)):
            a, b = intervals[i]
            if a <= l <= b:
                first = i
            if a <= r <= b:
                second = i
        print(first, second)
        if first < 0 and second < 0:
            flag = 1
            for i in range(len(intervals)-1):
                if intervals[i][1] < l < intervals[i+1][0]: first = i
                if intervals[i][1] < r < intervals[i+1][0]: second = i
            if first >= 0 and second >= 0:
                return intervals[:first+1] + [[l, r]] + intervals[second+1:]
            elif first >= 0 and second < 0:
                return intervals[:first+1] + [[l, r]]
            elif first < 0 and second >= 0:
                return [[l, r]] + intervals[second+1:]
            else:
                if r < intervals[0][0]: return [newInterval] + intervals
                elif l > intervals[-1][1]: return intervals + [newInterval]
                else: return [newInterval]
                 
        if first >= 0 and second >= 0:
            if first == second:
                return intervals
            else:
                return intervals[:first] + [[intervals[first][0], intervals[second][1]]] + intervals[second+1:]
        if first >= 0 and second < 0:
            flag = 1
            for i in range(first, len(intervals)-1):
                if intervals[i][1] < r < intervals[i+1][0]:
                    flag = 0
                    return intervals[:first] + [[intervals[first][0], r]] + intervals[i+1:]
            if flag:
                return intervals[:first] + [[intervals[first][0], r]]
        if first < 0 and second >= 0:
            flag = 1
            for i in range(second):
                if intervals[i][1] < l < intervals[i+1][0]:
                    flag = 0
                    return intervals[:i+1] + [[l, intervals[second][1]]] + intervals[second+1:]
            if flag:
                    return [[l, intervals[second][1]]] + intervals[second+1:]
```
