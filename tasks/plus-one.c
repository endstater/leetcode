#include <stdio.h>
#include <stdlib.h>

int* bigNumber(int n) {
    int* result = malloc(sizeof(int)*(n+1));
    result[0] = 1;
    for (int i = 1; i <= n; i++) {
        result[i] = 0;
    }
    return result;
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    digits[digitsSize-1]++;
    for (int i = digitsSize-1; i>=0&&digits[i] == 10; i--) {
        digits[i] = 0;
        if(i>0){
            digits[i-1]++;
        }
    }
    if (digits[0] == 0) {
        *returnSize = digitsSize+1;
        return bigNumber(digitsSize);
    }
    *returnSize = digitsSize;
    return digits;
}

int main() {
    int digits[] = {1,9,9,9,9};
    int size;

    int * num = plusOne(digits, 5, &size);
    return 0;
}