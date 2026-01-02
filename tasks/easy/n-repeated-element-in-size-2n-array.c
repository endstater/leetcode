#include <stdio.h>
#include <stdlib.h>

int repeatedNTimes(int* nums, int numsSize) {
    int* contains = malloc(sizeof(int) * 10000);
    for (int i = 0; i < 10000; ++i) {
        contains[i] = 0;
    }
    for (int i = 0; i < numsSize; ++i) {
        contains[nums[i]] += 1;
        if (contains[nums[i]] == numsSize / 2) {
            free(contains);
            return nums[i];
        }
    }
    free(contains);
    return 0;
}

int main() {

    int nums[] = {1,2,3,3};

    int num = repeatedNTimes(nums, 4);

    printf("%d\n", num);

    return 0;
}