#include <stdio.h>
#include <stdlib.h>

int test(int **x)
{
    return 0;
}


int main()
{
    int a[5][2];

    test(a);

    return 0;
}

dclass Solution {
    public int jump(int[] nums) {
        int end = 0, reach = 0, count = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            if (i + nums[i] > reach) {
                reach = i + nums[i];
                if (reach >= nums.length - 1) return count + 1;
            }
            if (i == end) {
                count += 1;
                end = reach;
            }
        }
        return count;
    }
}
