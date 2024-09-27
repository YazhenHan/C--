#include <string>

using namespace std;

class Solution {
public:
    int takeCharacters(string s, int k) {
        int abc[3] = {0, 0, 0};
        for (auto c : s) {
            abc[c - 'a']++;
        }
        if (abc[0] < k || abc[1] < k || abc[2] < k) return -1;
        int ans = s.size(), left = 0, right = 0;
        while (right < s.size() && left <= right) {
            abc[s[right] - 'a']--;
            while (abc[s[right] - 'a'] < k) {
                abc[s[left] - 'a']++;
                left++;
            }
            right++;
            ans = min(ans, (int)s.size() - (right - left));
        }
        return ans;
    }
};