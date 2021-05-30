#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int cmp_func(const void *a, const void *b)
{
    int ret = *(int *)a - *(int *)b;

    if (ret == 0)
        ret = *((int *)a + 1) - *((int *)b + 1);

    return ret;
}

bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity)
{
    int trip_list[4 * tripsSize];
    int load = 0;

    for (int i = 0; i < tripsSize; i++) {
        trip_list[4 * i] = trips[i][1];
        trip_list[4 * i + 1] = trips[i][0];
        trip_list[4 * i + 2] = trips[i][2];
        trip_list[4 * i + 3] = -trips[i][0];
    }

    qsort(trip_list, 2 * tripsSize, sizeof(int) * 2, cmp_func);

    for (int i = 0; i < 2 * tripsSize; i++) {
        load += trip_list[2 * i + 1];
        if (load > capacity)
            return false;
    }

    return true;
}