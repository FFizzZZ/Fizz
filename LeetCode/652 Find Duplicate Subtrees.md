## Leetcode

#### DFS
```
class Solution(object):
    def findDuplicateSubtrees(self, root):
        d = collections.defaultdict(int)
        ans = []
        def dfs(node):
            if not node: return "#"
            serial = "{}{}{}".format(node.val, dfs(node.left), dfs(node.right))
            d[serial] += 1
            if d[serial] == 2:
                ans.append(node)
            return serial
        dfs(root)
        return ans
```

#### Unique Identifier (Amazing!)
```
class Solution(object):
    def findDuplicateSubtrees(self, root):
        trees = collections.defaultdict()
        trees.default_factory = trees.__len__
        count = collections.defaultdict(int)
        ans = []
        def lookup(node):
            if node:
                uid = trees[node.val, lookup(node.left), lookup(node.right)]
                count[uid] += 1
                if count[uid] == 2:
                    ans.append(node)
                return uid
        lookup(root)
        return ans
```
