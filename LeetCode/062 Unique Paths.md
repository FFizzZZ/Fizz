```
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head: return None
        end = head
        count = 1
        while end.next:
            end = end.next
            count += 1
        end.next = head
        p = head
        k = k % count
        for _ in range(count - k - 1):
            p = p.next
        ans = p.next
        p.next = None
        return ans
```

## math
```
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return int(math.factorial(m+n-2) / math.factorial(m-1) / math.factorial(n-1))
```
