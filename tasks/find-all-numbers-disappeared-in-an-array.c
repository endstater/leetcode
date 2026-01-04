#include <stdio.h>
#include <stdlib.h>

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* arr = malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        arr[i] = i+1;
    }
    int size = numsSize;
    for (int i = 0; i < numsSize; i++) {
        if (arr[nums[i]-1] != 0) {
            arr[nums[i]-1] = 0;
            size--;
        }
    }
    *returnSize = size;
    int* result = malloc(sizeof(int) * size);
    for (int i = 0,j = 0;i < numsSize; i++) {
        if (arr[i] == 0) continue;
        result[j] = arr[i];
        j++;
    }
    free(arr);
    return result;
}

int main() {
    int v[] = {4,3,2,7,8,2,3,1};
    int returnSize;
    int* result = findDisappearedNumbers(v,8,&returnSize);
}
