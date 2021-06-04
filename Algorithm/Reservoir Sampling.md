## Reservoir Sampling
* https://www.jianshu.com/p/7a9ea6ece2af
* code
```
int *rs(int *arr, int size, int k)
{   
    int *reservoir = (int *)malloc(sizeof(int) * k);
  
    for (int i = 0; i < k; i++)
        reservoir[i] = arr[i];
    
    for (int i = k; i < size; i++) {
        int r = rand() % (i + 1);
        if (r < k) {
            reservoir[r] = arr[i];
        }
    }
    
    return reservoir;
}
```
