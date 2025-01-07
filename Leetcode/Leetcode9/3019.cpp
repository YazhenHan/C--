#include <string>

using namespace std;

class Solution {
public:
    int countKeyChanges(string s) {
        int ans = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] - s[i - 1] != 0 && abs(s[i] - s[i - 1]) != 32)
                ans++;
        }
        return ans;
    }
};