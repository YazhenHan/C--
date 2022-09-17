#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string ans; 
        ans.push_back(s[0]);
        for (int i = 0; i < s.size(); i++) {
            int left = i - 1, right = i + 1, temp = 1;
            while (left >= 0 && right < s.size()) {
                if (s[left] == s[right])
                    temp += 2;
                else
                    break;
                left--;
                right++;
            }
            if (temp > ans.size()) {
                ans = s.substr(i - temp / 2, temp);
            }
        }
        for (int i = 0; i < s.size(); i++) {
            int left = i, right = i + 1, temp = 0;
            while (left >= 0 && right < s.size()) {
                if (s[left] == s[right])
                    temp += 2;
                else
                    break;
                left--;
                right++;
            }
            if (temp > ans.size()) {
                ans = s.substr(i - temp / 2 + 1, temp);
            }
        }
        return ans;
    }
};