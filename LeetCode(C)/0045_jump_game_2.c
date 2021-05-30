#include <stdio.h>
#include <stdlib.h>



int jump(int* nums, int numsSize)
{
    int count = 0;
    int next = 0;
    int end = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i + nums[i] > next) {
            next = i + nums[i];
            if (next >= numsSize - 1)
                return count + 1;
        }

        if (i == end) {
            count += 1;
            end = next;
        }
    }

    return count;
}