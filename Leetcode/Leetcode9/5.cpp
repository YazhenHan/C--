#include <string>

using namespace std;

class Solution {
private:
    int getMiddle(const string & s, int cur) {
        int ans = 1;
        for (int i = 1; cur - i >= 0 && cur + i < s.size(); i++) {
            if (s[cur - i] != s[cur + i]) break;
            ans += 2;
        }
        return ans;
    }

    int getDouble(const string & s, int left, int right) {
        int ans = 0;
        for (int i = 0; left - i >= 0 && right + i < s.size(); i++) {
            if (s[left - i] != s[right + i]) break;
            ans += 2;
        }
        return ans;
    }
public:
    string longestPalindrome(string s) {
        string ans = s.substr(0, 1);
        for (int i = 0; i < s.size(); i++) {
            int temp = getMiddle(s, i);
            if (temp > ans.size()) {
                ans = s.substr(i - (temp - 1) / 2, temp);
            }
        }
        for (int i = 0; i + 1 < s.size(); i++) {
            int temp = getDouble(s, i, i + 1);
            if (temp > ans.size()) {
                ans = s.substr(i + 1 - temp / 2, temp);
            }
        }
        return ans;
    }
};