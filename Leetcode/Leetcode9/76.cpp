#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> um;
        int ans = 0;
        for (char c : t) {
            um[c]++;
            ans++;
        }

        int temp1 = 0, temp2 = s.size() - 1;
        int left = 0, right = 0;
        while (right < s.size()) {
            if (um.count(s[right])) {
                um[s[right]]--;
                if (um[s[right]] >= 0) ans--;
            }

            while (left < s.size() && (!um.count(s[left]) || um[s[left]] < 0)) {
                if (um.count(s[left]) && um[s[left]] < 0) um[s[left]]++;
                left++;
            }

            if (ans == 0 && right - left < temp2 - temp1) {
                temp1 = left;
                temp2 = right;
            }

            right++;
        }

        if (ans != 0) return "";
        return s.substr(temp1, temp2 - temp1 + 1);
    }
};