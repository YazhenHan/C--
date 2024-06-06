#include <string>

using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int n = s.size() - 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                ans += n - i;
                n--;
            }
        }
        return ans;
    }
};