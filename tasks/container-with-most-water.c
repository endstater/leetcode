#include <stdio.h>
#include <stdlib.h>

int mmax(int x, int y) {
    return x > y ? x : y;
}

int mmin(int x, int y) {
    return x < y ? x : y;
}

int water(int x, int y,int l,int r) {
    return mmin(x, y)*(r-l);
}

int maxArea(int* height, int heightSize) {
    int l = 0;
    int r = heightSize - 1;
    int max = 0;
    while (l < r) {
        max = mmax(max, water(height[l], height[r],l,r));
        if (height[l] > height[r]) r--;
        else l++;
    }
    return max;
}

int main() {
    int height[] = {1,8,6,2,5,4,8,3,7};

    int area = maxArea(height, 9);
    printf("%d\n", area);
    return 0;
}