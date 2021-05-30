int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize)
{
    int *ans = (int *)malloc(sizeof(int) * (n + 1));
    
    memset(ans, 0, sizeof(int) * n);
    
    for (int i = 0; i < bookingsSize; i++) {
        int first = bookings[i][0] - 1;
        int last = bookings[i][1] - 1;
        int seats = bookings[i][2];
        
        ans[first] += seats;
        ans[last + 1] -= seats;
    }
    
    for (int i = 1; i < n; i++)
        ans[i] += ans[i - 1];
    
    *returnSize = n;
    
    return ans;
}