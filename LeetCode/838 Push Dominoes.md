```
class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        if n == 1: return dominoes
        dominoes = list(dominoes)
        while True:
            new = dominoes[:]
            for i in range(n):
                if dominoes[i] == ".":
                    if i == 0:
                        if dominoes[i + 1] == "L":
                            new[i] = "L"
                    elif i == n - 1:
                        if dominoes[i - 1] == "R":
                            new[i] = "R"
                    else:
                        if dominoes[i - 1] == "R":
                            if dominoes[i + 1] == "L":
                                new[i] = "."
                            else:
                                new[i] = "R"
                        elif dominoes[i + 1] == "L":
                            new[i] = "L"
            if new != dominoes:
                dominoes = new
            else:
                break
        return "".join(dominoes)
```
