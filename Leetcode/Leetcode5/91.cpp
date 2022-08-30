#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int ans = 0, temp1 = 1, temp2 = 1;
        if (s[0] == '0') return 0;
        if (s.size() == 1) return 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2')
                    ans = temp1;
                else
                    return 0;
            } else if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
                ans = temp1 + temp2;
            } else {
                ans = temp2;
            }
            temp1 = temp2;
            temp2 = ans;
        }
        return ans;
    }
};