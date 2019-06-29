## Leetcode
### Recurse
```
class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        if not head: return None
        mid = self.findMiddle(head)
        node = TreeNode(mid.val)
        if head == mid:
            return node
        node.left = self.sortedListToBST(head)
        node.right = self.sortedListToBST(mid.next)
        return node              
    def findMiddle(self, head):
        pre = None
        slow = head
        fast = head
        while fast and fast.next:
            pre = slow
            slow = slow.next
            fast = fast.next.next
        if pre:
            pre.next = None
        return slow
```
### Recurse + Conversion to Array
```
class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        vals = self.mapListToValues(head)
        return self.convertListToBST(0, len(vals) - 1, vals)
    def convertListToBST(self, l, r, vals):
        if l > r: return None
        mid = (l + r) // 2
        node = TreeNode(vals[mid])
        node.left = self.convertListToBST(l, mid - 1, vals)
        node.right = self.convertListToBST(mid + 1, r, vals)
        return node
    def mapListToValues(self, head):
        vals = []
        while head:
            vals.append(head.val)
            head = head.next
        return vals
```

### Inorder Simulation
```
class Solution:
    def findSize(self, head):
        ptr = head
        c = 0
        while ptr:
            ptr = ptr.next
            c += 1
        return c
    def sortedListToBST(self, head):
        size = self.findSize(head)
        def convert(l, r):
            nonlocal head
            if l > r: return None
            mid = (l + r) // 2
            left = convert(l, mid - 1)
            node = TreeNode(head.val)   
            node.left = left
            head = head.next
            node.right = convert(mid + 1, r)
            return node
        return convert(0, size - 1)
```
