#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> um;
        int ans = -1;
        for (int i = 0; i < s.size(); i++) {
            if (um.count(s[i])) {
                ans = max(ans, i - um[s[i]] - 1);
            } else {
                um[s[i]] = i;
            }
        }
        return ans;
    }
};