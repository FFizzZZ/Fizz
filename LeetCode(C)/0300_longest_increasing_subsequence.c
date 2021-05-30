#include <stdio.h>
#include <stdlib.h>

int find_index(int x, int *arr, int len)
{
    int l = 0;
    int r = len;

    while (l < r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid;
    }

    return l;
}


int lengthOfLIS(int* nums, int numsSize)
{
    int arr[numsSize];
    int len = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int idx = find_index(nums[i], arr, len);
        arr[idx] = nums[i];

        if (idx == len)
            len++;
    }

    return len;
}