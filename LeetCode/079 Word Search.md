```
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        for i in range(len(board)):
            for j in range(len(board[0])):
                if self.move(i, j, board, 0, word):
                    return True
        return False
    def move(self, i, j, board, index, word):
        if board[i][j] == word[index]:
            index += 1
            if index == len(word): return True
            temp = board[i][j]
            board[i][j] = '#'
            m, n = len(board), len(board[0])
            ans = False
            if not ans and i + 1 < m and board[i + 1][j] != '#':
                ans = self.move(i + 1, j, board, index, word)
            if not ans and i - 1 > -1 and board[i - 1][j] != '#':
                ans = self.move(i - 1, j, board, index, word)
            if not ans and j + 1 < n and board[i][j + 1] != '#':
                ans = self.move(i, j + 1, board, index, word)
            if not ans and j - 1 > -1 and board[i][j - 1] != '#':
                ans = self.move(i, j - 1, board, index, word)
            board[i][j] = temp
            return ans
        return False
        
```
        
