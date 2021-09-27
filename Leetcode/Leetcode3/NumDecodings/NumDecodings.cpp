#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 1)
            return s[0] == '0' ? 0 : 1;
        int ans = 0;
        int flag0 = 1, flag1 = 1, flag2 = 1;
        if (s[0] == '0') {
            flag0 = 0;
            flag1 = 0;
            flag2 = 0;
        }
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == '0') {
                if (s[i] == '0')
                    return 0;
                else
                    ans = flag0;
            }
            else if (s[i - 1] == '2') {
                if (s[i] == '0')
                    ans = flag1;
                else if (s[i] > '6')
                    ans = flag2;
                else
                    ans = flag1 + flag2;
            }
            else if (s[i - 1] > '2') {
                if (s[i] == '0')
                    return 0;
                else
                    ans = flag2;
            }
            else if (s[i] == '0')
                ans = flag1;
            else
                ans = flag1 + flag2;
            flag0 = flag1;
            flag1 = flag2;
            flag2 = ans;
        }
        return ans;
    }
};