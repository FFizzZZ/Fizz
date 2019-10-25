## Leetcode

#### Recursion

```
class Solution:
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
        if not pre: return None
        root = TreeNode(pre[0])
        if len(pre) == 1:
            return root
        idx = post.index(pre[1]) + 1
        root.left = self.constructFromPrePost(pre[1: idx + 1], post[:idx])
        root.right = self.constructFromPrePost(pre[idx + 1:], post[idx: -1])
        return root
```

#### Recursion (Space Saving Variant)
```
class Solution:
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
        def make(i, j, N):
            if N == 0: return None
            root = TreeNode(pre[i])
            if N == 1: return root
            for L in range(N):
                if post[j + L - 1] == pre[i + 1]:
                    break
            root.left = make(i + 1, j, L)
            root.right = make(i + L + 1, j + L, N - 1 - L)
            return root
        return make(0, 0, len(pre))
```


#### Easy to read
```
class Solution:
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
        preIndex = postIndex = 0
        def helper():
            nonlocal preIndex, postIndex
            if preIndex >= len(pre):
                return None
            root = TreeNode(pre[preIndex])
            preIndex += 1
            if root.val != post[postIndex]:
                root.left = helper()
            if root.val != post[postIndex]:
                root.right = helper()
            postIndex += 1
            return root
        return helper()
```
