#include <string>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int a0 = 0, b1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                b1 = min(a0, b1) + 1;
            } else {
                b1 = min(a0, b1);
                a0++;
            }
        }
        return min(a0, b1);
    }
};
