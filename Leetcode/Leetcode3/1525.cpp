#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int numSplits(string s) {
        unordered_set<char> cs;
        vector<int> left_flags(26, 0);
        for (char c : s) {
            cs.insert(c);
            left_flags[c - 'a']++;
        }
        int total = cs.size();
        int ans = 0;
        unordered_set<char> cs2;
        for (int i = 0; i < s.size(); i++) {
            cs2.insert(s[i]);
            left_flags[s[i] - 'a']--;
            if (left_flags[s[i] - 'a'] == 0) cs.erase(s[i]);
            if (cs2.size() == cs.size())
                ans++;
        }
        return ans;
    }
};