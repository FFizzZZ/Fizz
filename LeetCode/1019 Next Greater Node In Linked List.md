```
class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        stack = []
        ans = []
        idx = 0
        while head:
            val = head.val
            ans.append(0)
            while stack and stack[-1][1] < val:
                ans[stack.pop()[0]] = val
            stack.append([idx, val])
            idx += 1
            head = head.next
        return ans
```
