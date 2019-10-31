```
class Codec:
    def serialize(self, root):
        if not root: return "#"
        ans = str(root.val) + "$" + self.serialize(root.left) + "$" + self.serialize(root.right)
        return ans
        
    def deserialize(self, data):
        nums = data.split("$")
        if nums[0] == "#": return None
        root = TreeNode(int(nums[0]))
        stack = [(root, False)]
        for char in nums[1:]:
            node, state = stack.pop()
            if char == "#":
                if not state:
                    stack.append((node, True))
            else:
                new = TreeNode(int(char))
                if not state:
                    node.left = new
                    stack.append((node, True))
                else:
                    node.right = new
                stack.append((new, False))
        return root
```

## Leetcode

#### Recursion
```
class Codec:
    def serialize(self, root):
        if not root: return "#"
        ans = str(root.val) + "$" + self.serialize(root.left) + "$" + self.serialize(root.right)
        return ans

    def deserialize(self, data):
        it = iter(data.split("$"))
        def recur():
            val = next(it)
            if val == "#":
                return None
            node = TreeNode(int(val))
            node.left = recur()
            node.right = recur()
            return node
        return recur()
```
