```
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if not root: return []
        ans = []
        self.f(root, ans)
        return ans       
    def f(self, node, ans):
        ans.append(node.val)
        for i in node.children:
            self.f(i, ans)
```
