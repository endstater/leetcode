#include <stdio.h>
#include <stdlib.h>

int sum(int* listSizes, int listSizesSize){
    int sum = 0;
    for(int i = 0; i < listSizesSize; i++) {
        sum += listSizes[i];
    }
    return sum;
}

int* fairCandySwap(int* aliceSizes, int aliceSizesSize, int* bobSizes, int bobSizesSize, int* returnSize) {
    int aliceSum = sum(aliceSizes, aliceSizesSize);
    int bobSum = sum(bobSizes, bobSizesSize);
    for(int i = aliceSizesSize-1; i >= 0; --i) {
        for(int j = bobSizesSize-1; j >= 0; --j) {
            if ((bobSizes[j] + aliceSum - aliceSizes[i]) == (bobSum + aliceSizes[i] - bobSizes[j])){
                returnSize[0] = 2;
                int* arr = malloc(sizeof(int) * 2);
                arr[0] = aliceSizes[i];
                arr[1] = bobSizes[j];
                return arr;
            }
        }
    }
    return returnSize;
}

int main() {
    int aliceSizes[] = {1, 1};
    int bobSizes[] = {2, 2};
    int returnSize[] = {0};

    int *arr = fairCandySwap(aliceSizes, 2, bobSizes, 2, returnSize);

    printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);

    return 0;
}