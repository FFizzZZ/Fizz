#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int size = 50000;

int hash(int key)
{
    int r = key % size;
    
    return r < 0 ? r + size : r;
}

void insert(int *keys, int *values, int key, int value)
{
    int index = hash(key);

    while (values[index] != 0)
        index = (index + 1) % size;

    keys[index] = key;
    values[index] = value;
}

int search(int *keys, int *values, int key)
{
    int index = hash(key);

    while (values[index] != 0) {
        if (keys[index] == key)
            return values[index];
        index = (index + 1) % size;
    }

    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int keys[size];
    int values[size];
    int cmplmt;
    int value;

    memset(values, 0, sizeof(values));

    for (int i = 0; i < numsSize; i++) {
        cmplmt = target - nums[i];
        value = search(keys, values, cmplmt);
        printf("%d\n", nums[i]);
        if (value != 0) {
            int *ans = (int *)malloc(sizeof(int) * 2);
            ans[0] = value - 1;
            ans[1] = i;
            *returnSize = 2;
            return ans;
        }

        insert(keys, values, nums[i], i + 1);
    }

    return NULL;
}
