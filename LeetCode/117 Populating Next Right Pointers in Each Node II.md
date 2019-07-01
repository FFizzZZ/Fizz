```
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        p = root
        while root:
            node = root
            pre = None
            first = None
            while node:
                if node.left:
                    if pre:
                        pre.next = node.left
                    else:
                        first = node.left
                    pre = node.left
                if node.right:
                    if pre:
                        pre.next = node.right
                    else:
                        first = node.right
                    pre = node.right
                node = node.next
            root = first
        return p
```

## Leetcode
```
class Solution:
    def connect(self, node):
        p = node
        head = tail = Node(0, None, None, None)
        while node:
            tail.next = node.left
            if tail.next:
                tail = tail.next
            tail.next = node.right
            if tail.next:
                tail = tail.next
            node = node.next
            if not node:
                node = head.next
                tail = head
        return p
```
