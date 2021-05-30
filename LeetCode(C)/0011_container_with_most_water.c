int maxArea(int* height, int heightSize)
{
    int ret = 0;
    int l = 0;
    int r = heightSize - 1;

    while (l < r) {
        int cur;
        if (height[l] > height[r]) {
            cur = height[r] * (r - l);
            r--;
        } else {
            cur = height[l] * (r - l);
            l++;
        }

        ret = cur > ret ? cur : ret;
    }

    return ret;
}