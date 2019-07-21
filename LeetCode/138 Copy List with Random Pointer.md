## Leetcode
#### Recurse
```
    def copyRandomList(self, head: 'Node') -> 'Node':
        return self.f(head, {})
    def f(self, root, d):
        if not root: return
        if root in d: return d[root]
        node = Node(root.val, None, None)
        d[root] = node
        node.next = self.f(root.next, d)
        node.random = self.f(root.random, d)
        return node
```
#### Iteration
```
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head: return None
        p = head
        while p:
            node = Node(p.val, p.next, None)
            p.next = node
            p = node.next
        p = head
        while p:
            node = p.next
            if p.random:
                node.random = p.random.next
            p = node.next
        node, head, cur = head, head.next, head.next
        while node:
            node.next = cur.next
            node = node.next
            if node:
                cur.next = node.next
                cur = cur.next
        return head
```


