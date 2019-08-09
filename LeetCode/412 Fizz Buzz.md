```
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        ans = [0] * n
        for i in range(1, n + 1):
            three = i % 3 == 0
            five = i % 5 == 0
            if three and five:
                ans[i - 1] = 'FizzBuzz'
            elif three:
                ans[i - 1] = 'Fizz'
            elif five:
                ans[i - 1] = 'Buzz'
            else:
                ans[i - 1] = str(i)
        return ans
```

## Leetcode
```
class Solution:
    def fizzBuzz(self, n):
        ans = []
        for num in range(1,n+1):
            divisible_by_3 = (num % 3 == 0)
            divisible_by_5 = (num % 5 == 0)
            num_ans_str = ""
            if divisible_by_3:
                num_ans_str += "Fizz"
            if divisible_by_5:
                num_ans_str += "Buzz"
            if not num_ans_str:
                num_ans_str = str(num)
            ans.append(num_ans_str)  
        return ans
```
