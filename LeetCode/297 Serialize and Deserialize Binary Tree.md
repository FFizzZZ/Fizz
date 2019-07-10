```
class Codec:
    def serialize(self, root):
        if not root: return str([None])
        ans = []
        queue = [root]
        while queue:
            node = queue.pop(0)
            if node:
                ans.append(node.val)
                queue.append(node.left)
                queue.append(node.right)
            else:
                ans.append(None)
        while ans and ans[-1] == None:
            ans.pop()
        return str(ans)
    def deserialize(self, data):
        nums = data[1:-1].split(', ')
        if nums[0] == 'None': return None
        head = TreeNode(int(nums.pop(0)))
        queue = [head]
        while nums:
            node = queue.pop(0)
            left = nums.pop(0)
            right = nums.pop(0) if nums else 'None'
            if left != 'None':
                left = TreeNode(int(left))
                node.left = left
                queue.append(left)
            if right != 'None':
                right = TreeNode(int(right))
                node.right = right
                queue.append(right)
        return head
```

## Leetcode
```
class Codec:
    def serialize(self, root):
        if not root: return '#'
        return str(root.val) + ',' + self.serialize(root.left) + ',' + self.serialize(root.right)
    def deserialize(self, data):
        s = data.split(',')
        return self.f(s)
    def f(self, s):
        val = s.pop(0)
        if val != '#':
            node = TreeNode(int(val))
            node.left = self.f(s)
            node.right = self.f(s)
            return node
```
