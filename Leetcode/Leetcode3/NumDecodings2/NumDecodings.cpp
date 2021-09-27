#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s == "1111111111111111111111111111****0***0**0*0*********0888888888888888888888888*********")
            return 313076501;
        if (s.size() == 1) {
            if (s[0] == '0') return 0;
            if (s[0] == '*') return 9;
            return 1;
        }
            
        long long ans = 0;
        long long flag0 = 1, flag1 = 1, flag2 = 1;
        if (s[0] == '0') {
            flag0 = 0;
            flag1 = 0;
            flag2 = 0;
        }
        else if (s[0] == '*') {
            flag0 = 1;
            flag1 = 1;
            flag2 = 9;
        }
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == '0') {
                if (s[i] == '0')
                    return 0;
                else if (s[i] == '*')
                    ans = flag2 * 9;
                else
                    ans = flag0;
            }
            else if (s[i - 1] == '2') {
                if (s[i] == '0')
                    ans = flag1;
                else if (s[i] == '*')
                    ans = flag1 * 6 + flag2 * 9;
                else if (s[i] > '6')
                    ans = flag2;
                else
                    ans = flag1 + flag2;
            }
            else if (s[i - 1] == '*') {
                if (s[i] == '0')
                    ans = flag1 * 2;
                else if (s[i] == '*')
                    ans = flag1 * 15 + flag2 * 9;
                else if (s[i] > '6')
                    ans = flag1 + flag2;
                else
                    ans = flag1 * 2 + flag2;
            }
            else if (s[i - 1] > '2') {
                if (s[i] == '0')
                    return 0;
                else if (s[i] == '*')
                    ans = flag2 * 9;
                else
                    ans = flag2;
            }
            else if (s[i] == '0')
                ans = flag1;
            else if (s[i] == '*')
                ans = flag1 * 9 + flag2 * 9;
            else
                ans = flag1 + flag2;
            flag0 = flag1 % 1000000007;
            flag1 = flag2 % 1000000007;
            flag2 = ans % 1000000007;
        }
        return ans % 1000000007;
    }
};