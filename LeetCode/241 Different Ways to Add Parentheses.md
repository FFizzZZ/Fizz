## Leetcode
```
class Solution:
    def diffWaysToCompute(self, input: str) -> List[int]:
        if input.isdigit(): return [int(input)]
        ans = []
        for idx, val in enumerate(input):
            if val in ["+", "-", "*"]:
                left = self.diffWaysToCompute(input[:idx])
                right = self.diffWaysToCompute(input[idx + 1:])
                if val == "+":
                    ans.extend([x + y for x in left for y in right])
                elif val == "-":
                    ans.extend([x - y for x in left for y in right])
                else:
                    ans.extend([x * y for x in left for y in right])
        return ans
```
        
```
class Solution:
    def diffWaysToCompute(self, input: str) -> List[int]:
        if input.isdigit(): return [int(input)]
        ans = []
        op = {"+": operator.add, "-": operator.sub, "*": operator.mul}
        for idx, val in enumerate(input):
            if val in ["+", "-", "*"]:
                left = self.diffWaysToCompute(input[:idx])
                right = self.diffWaysToCompute(input[idx + 1:])
                for x in left:
                    for y in right:
                        ans.append(op[val](x, y))
        return ans
```
        
        
        
        
        
        
        
        
        
        

