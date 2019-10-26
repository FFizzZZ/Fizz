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
            node = TreeNode(pre[i])
            if N == 1: return node
            idx = post.index(pre[i + 1], j, j + N)
            L = idx - j + 1
            node.left = make(i + 1, j, L)
            node.right = make(i + 1 + L, j + L, N - L - 1)
            return node
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

#### Iteration
```
class Solution:
    def constructFromPrePost(self, pre: List[int], post: List[int]) -> TreeNode:
        stack = [TreeNode(pre[0])]
        idx = 0
        for val in pre[1:]:
            node = TreeNode(val)
            while stack[-1].val == post[idx]:
                stack.pop()
                idx += 1
            if stack[-1].left:
                stack[-1].right = node
            else:
                stack[-1].left = node
            stack.append(node)
        return stack[0]
```

