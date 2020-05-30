```
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        ans = []
        self.dfs(root, "", ans)
        return ans
        
    def dfs(self, node, path, ans):
        if not node:
            return
        path += str(node.val)
        if not node.left and not node.right:
            ans.append(path)
            return
        path += "->"
        self.dfs(node.left, path, ans)
        self.dfs(node.right, path, ans)
```
