```
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        ans = []
        self.f(root, [], sum, ans)
        return ans
    def f(self, root, path, sum, ans):
        if not root: return
        sum -= root.val
        path.append(root.val)
        if not root.left and not root.right and sum == 0:
            ans.append(path[:])
        else:
            self.f(root.left, path, sum, ans)
            self.f(root.right, path, sum, ans)
        path.pop()
```
