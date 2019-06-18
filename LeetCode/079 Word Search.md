```
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.move(i, j, board, word, []):
                    return True
        return False
    def move(self, i, j, board, word, path):
        if board[i][j] == word[0]:
            word = word[1:]
            if not word: return True
            path.append((i, j))
            m, n = len(board), len(board[0])
            ans = False
            if not ans and i + 1 < m and (i + 1, j) not in path:
                ans = self.move(i + 1, j, board, word, path)
            if not ans and i - 1 > -1 and (i -1, j) not in path:
                ans = self.move(i - 1, j, board, word, path)
            if not ans and j + 1 < n and (i, j + 1) not in path:
                ans = self.move(i, j + 1, board, word, path)
            if not ans and j - 1 > -1 and (i, j - 1) not in path:
                ans = self.move(i, j - 1, board, word, path)
            path.pop()
            return ans
        return False
```
        
