#include <stdio.h>

int sumFourDivisors(int * nums, int numsSize) {
    int answer = 0;
    for (int j = 0; j < numsSize; ++j) {
        int divs = 2;
        int sum = nums[j]+ 1;

        for (int i = 2; i*i <= nums[j]; ++i) {
            if (i*i == nums[j]){
                ++divs;
                sum+=i;
            } else if (nums[j] % i == 0){
                divs+=2;
                if (divs > 4) break;
                sum+=i;
                sum+=nums[j]/i;
            }
        }
        if (divs == 4) answer+=sum;
    }
    return answer;
}

int main() {
    int v[] = {21,4,7};
    int answer = sumFourDivisors(v,3);
    printf("%d\n", answer);
}
