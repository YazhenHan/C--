#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    bool check(unordered_map<char, int>& um, unordered_map<char, int>& um2) {
        for (const auto& p : um) {
            if (um2[p.first] < p.second)
                return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> um, um2;
        for (auto c : t)
            um[c]++;
        int l = 0, r = 0, len = INT32_MAX, ansL = -1;
        while (r < s.size()) {
            if (um.count(s[r]))
                um2[s[r]]++;
            while (check(um, um2) && l <= r) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if (um.count(s[l]))
                    um2[s[l]]--;
                l++;
            }
            r++;
        }
        return ansL == -1 ? "" : s.substr(ansL, len);
    }
};