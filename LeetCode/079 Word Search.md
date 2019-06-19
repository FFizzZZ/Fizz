```
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.move(i, j, board, 0, word, {}):
                    return True
        return False
    def move(self, i, j, board, index, word, path):
        if board[i][j] == word[index]:
            index += 1
            if index == len(word): return True
            path[(i, j)] = 1
            m, n = len(board), len(board[0])
            ans = False
            if not ans and i + 1 < m and (i + 1, j) not in path:
                ans = self.move(i + 1, j, board, index, word, path)
            if not ans and i - 1 > -1 and (i -1, j) not in path:
                ans = self.move(i - 1, j, board, index, word, path)
            if not ans and j + 1 < n and (i, j + 1) not in path:
                ans = self.move(i, j + 1, board, index, word, path)
            if not ans and j - 1 > -1 and (i, j - 1) not in path:
                ans = self.move(i, j - 1, board, index, word, path)
            del path[(i, j)]
            return ans
        return False
```
        
