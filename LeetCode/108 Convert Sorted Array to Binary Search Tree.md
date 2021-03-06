```
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        return self.f(0, len(nums) - 1, nums)
    def f(self, l, r, nums):
        if l > r: return None
        mid = (l + r) // 2
        node = TreeNode(nums[mid])
        node.left = self.f(l, mid - 1, nums)
        node.right = self.f(mid + 1, r, nums)
        return node
```

## Leetcode
### Iteration
```
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if not nums: return None
        head = TreeNode(0)
        stack = [(head, 0, len(nums) - 1)]
        while stack:
            node, l, r = stack.pop()
            mid = (l + r) // 2
            node.val = nums[mid]
            if l <= mid - 1:
                node.left = TreeNode(0)
                stack.append((node.left, l, mid - 1))
            if mid + 1 <= r:
                node.right = TreeNode(0)
                stack.append((node.right, mid + 1, r))
        return head
```
