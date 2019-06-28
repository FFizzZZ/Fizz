# 并查集 UnionFind
https://mp.weixin.qq.com/s/dsnzutDYYiIsZp2mT-R3Og  

并查集是一种树型的数据结构，用于处理一些不相交集合（Disjoint Sets）的合并及查询问题
* 基于树高度的合并优化: 合并的时候应该是矮的树往高的树上合并
* 路径压缩优化：查找的时候，直接把路径上的孩子都指向根，但是这样调整的话，树的高度可能发生变化，合并的时候再按秩优化就不准了，重新算的话比较麻烦，所以这两者优化方式根据情况选其一即可。

```
class UnionFind_MergeOptimize:
    def __init__(self, n):
        self.elements = [-1] * n
        self.heights = [1] * n
    def find(self, x):
        while self.elements[x] != -1:
            x = self.elements[x]
        return x
    def union(self, x, y):
        rootx = self.find(x)
        rooty = self.find(y)
        print(rootx, rooty)
        if rootx != rooty:
            if self.heights[rootx] > self.heights[rooty]:
                self.elements[rooty] = rootx
            elif self.heights[rootx] < self.heights[rooty]:
                self.elements[rootx] = rooty
            else:
                self.elements[rootx] = rooty
                self.heights[rooty] += 1
            self.elements[rootx] = rooty
    def count(self):
        return self.elements.count(-1)
    def print(self):
        print(self.elements)
        print(self.heights)
```

```
class UnionFind_PathOptimize:
    def __init__(self, n):
        self.elements = [-1] * n
    def find(self, x):
        root = x
        while self.elements[root] != -1:
            root = self.elements[root]
        while root != x:
            temp = x
            x = self.elements[x]
            self.elements[temp] = root
        return x
    def union(self, x, y):
        rootx = self.find(x)
        rooty = self.find(y)
        if rootx != rooty:
            self.elements[rootx] = rooty
    def count(self):
        return self.elements.count(-1)
    def print(self):
        print(self.elements)
```
