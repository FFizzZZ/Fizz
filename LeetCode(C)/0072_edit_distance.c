#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int minDistance(char * word1, char * word2)
{

class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        int m = n + 1;
        for (int i = 0; i < n; i++)
            if (nums[i] < 1 || nums[i] > n) nums[i] = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % m != 0) nums[nums[i] % m - 1] += m;
        }
        for (int i = 0; i < n; i++)
            if (nums[i] < m) return i + 1;
        return m;
    }
}













