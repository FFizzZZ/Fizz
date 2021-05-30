int cmp_func(const void *x, const void *y)
{
    return *(int *)x - *(int *)y;
}

int *build_item(int x, int y, int z)
{
    int *item = (int *)malloc(sizeof(int) * 3);

    item[0] = x;
    item[1] = y;
    item[2] = z;

    return item;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int **ans = NULL;
    int len = 1;
    int idx = 0;

    ans = (int **)malloc(sizeof(int *) * len);
    *returnColumnSizes = (int *)malloc(sizeof(int) * len);
    
    qsort(nums, numsSize, sizeof(int), cmp_func);

    for (int i = 0; i < numsSize - 2; i++) {
        /* skip duplicate cases */
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        int l = i + 1;
        int r = numsSize - 1;

        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];

            if (sum == 0) {
                int *item = build_item(nums[i], nums[l], nums[r]);
                ans[idx] = item;
                (*returnColumnSizes)[idx] = 3;

                if (++idx == len) {
                    len *= 2;
                    ans = (int **)realloc(ans, sizeof(int *) * len);
                    *returnColumnSizes = (int *)realloc(*returnColumnSizes, sizeof(int) * len);
                }

                while (l < r && nums[l] == nums[l + 1])
                    l++;

                l++;
                r--;
            } else if (sum < 0)
                l++;
            else
                r--;
        }
    }

    *returnSize = idx;

    return ans;
}