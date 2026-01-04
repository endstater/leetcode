#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int given = 0, l = 0, r = 0;

        while (s.size() > l && g.size() > r){
            if (s[l] >= g[r]) {
                ++l;
                ++r;
                ++given;
            } else {
                ++l;
            }
        }
        return given;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> g = {1,2};
    vector<int> s = {1,2,3};

    int answer = sol.findContentChildren(g, s);
    cout << answer << endl;
}