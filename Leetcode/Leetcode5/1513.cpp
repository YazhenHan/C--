#include <string>

using namespace std;

class Solution {
public:
    int numSub(string s) {
        int ans = 0, left = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                left = i + 1;
            else
                ans = (ans + (i - left + 1)) % 1000000007;
        }
        return ans;
    }
};