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
class Node:
    def __init__(self,s,e):
        self.e = e
        self.s = s
        self.left = None
        self.right = None


class MyCalendar(object):

    def __init__(self):
        self.root = None

    def book_helper(self,s,e,node):
        if s>=node.e:
            if node.right:
                return self.book_helper(s,e,node.right)
            else:
                node.right = Node(s,e)
                return True
        elif e<=node.s:
            if node.left:
                return self.book_helper(s,e,node.left)
            else:
                node.left = Node(s,e)
                return True
        else:
            return False
        
    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: bool
        """
        if not self.root:
            self.root = Node(start,end)
            return True
        return self.book_helper(start,end,self.root)
```
