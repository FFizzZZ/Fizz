```
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root: return []
        queue = [root]
        ans = []
        while queue:
            res = []
            temp = []
            for i in queue:
                if i:
                    temp.append(i.left)
                    temp.append(i.right)
                    res.append(i.val)
            if res:
                ans.append(res)
            queue = temp
        return ans
```
