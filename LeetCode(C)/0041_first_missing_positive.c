#include <stdio.h>
#include <stdlib.h>

int firstMissingPositive(int* nums, int numsSize)
{
    int m = numsSize + 1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > numsSize || nums[i] < 1)
            nums[i] = 0;
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] % m != 0)
            nums[nums[i] % m - 1] += m; 
    }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < m)
            return i + 1;
    }
}