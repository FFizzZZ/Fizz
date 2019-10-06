```
class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        row, col = len(M), len(M[0])
        ans = [[0] * col for _ in range(row)]
        for i in range(row):
            for j in range(col):
                cnt = 0
                for x in range(i - 1, i + 2):
                    for y in range(j - 1, j + 2):
                        if 0 <= x < row and 0 <= y < col:
                            ans[i][j] += M[x][y]
                            cnt += 1
                ans[i][j] = math.floor(ans[i][j] / cnt)
        return ans
```
        
## Leetcode
#### In-place
```
class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        row, col = len(M), len(M[0])
        for i in range(row):
            for j in range(col):
                cnt = 0
                tmp = 0
                for x in range(i - 1, i + 2):
                    for y in range(j - 1, j + 2):
                        if 0 <= x < row and 0 <= y < col:
                            tmp += M[x][y] & 0xff
                            cnt += 1
                M[i][j] |= (math.floor(tmp / cnt) << 8)
        for i in range(row):
            for j in range(col):
                M[i][j] >>= 8
        return M
```

#### FASTEST
```
class Solution:
    def imageSmoother(self, M):
        R = len(M)
        C = len(M[0])
        if R==1 and C==1:
            return M
        else:
            # empty matrix
            ans = [[0]*C for _ in range(R)]
            for i in range(1,R-1):
                for j in range(1,C-1):
                    ans[i][j] = (M[i-1][j-1] + M[i-1][j] + M[i-1][j+1] + 
                                 M[i][j-1] + M[i][j] + M[i][j+1] +
                                 M[i+1][j-1] + M[i+1][j] + M[i+1][j+1])//9
            if R==1:
                for j in range(1,C-1):
                    ans[0][j] = (M[0][j-1] + M[0][j] + M[0][j+1])//3
                ans[0][0] = (M[0][0]+M[0][1])//2
                ans[0][C-1] = (M[0][C-2]+M[0][C-1])//2
            elif C==1:
                for i in range(1,R-1):
                    ans[i][0] = (M[i-1][0] + M[i][0] + M[i+1][0])//3
                ans[0][0] = (M[0][0]+M[1][0])//2
                ans[R-1][0] = (M[R-2][0]+M[R-1][0])//2
            else:
                for i in [0,R-1]:
                    if i == 0:
                        i2 = 1
                    else:
                        i2 = R-2
                    for j in range(1,C-1):
                        ans[i][j] = (M[i][j-1] + M[i][j] + M[i][j+1] +
                                     M[i2][j-1] + M[i2][j] + M[i2][j+1])//6
                    ans[i][0] = (M[i][0] + M[i][1] + M[i2][0] + M[i2][1])//4
                    ans[i][C-1] = (M[i][C-2] + M[i][C-1] + M[i2][C-2] + M[i2][C-1])//4
                for j in [0,C-1]:
                    if j == 0:
                        j2 = 1
                    else:
                        j2 = C-2
                    for i in range(1,R-1):
                        ans[i][j] = (M[i-1][j] + M[i][j] + M[i+1][j] +
                                     M[i-1][j2] + M[i][j2] + M[i+1][j2])//6
                    ans[0][j] = (M[0][j] + M[1][j] + M[0][j2] + M[1][j2])//4
                    ans[R-1][j] = (M[R-2][j] + M[R-1][j] + M[R-2][j2] + M[R-1][j2])//4
            return ans
```
