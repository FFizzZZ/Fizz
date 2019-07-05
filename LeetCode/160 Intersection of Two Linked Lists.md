## Leetcode
#### When A reaches the end, then redirect it to the head of B; similarly when B reaches the end, redirect it the head of A.
```
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        if not headA or not headB: return None
        a, b = headA, headB
        while a != b:
            a = a.next if a else headB
            b = b.next if b else headA
        return a
```
#### Hash Table
```
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        d = {}
        while headA:
            d[headA] = 1
            headA = headA.next
        while headB:
            if headB in d:
                return headB
            headB = headB.next
```
