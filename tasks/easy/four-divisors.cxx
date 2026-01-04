#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int answer = 0;
        for (auto v : nums) {
            int divs = 2;
            int sum = v + 1;

            for (int i = 2; i*i <= v; ++i) {
                if (i*i == v ){
                    ++divs;
                    sum+=i;
                } else if (v % i == 0){
                    divs+=2;
                    if (divs > 4) break;
                    sum+=i;
                    sum+=v/i;
                }
            }
            if (divs == 4) answer+=sum;
        }
        return answer;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> v({21,4,7});
    int answer = sol.sumFourDivisors(v);
    cout << answer << endl;
}
