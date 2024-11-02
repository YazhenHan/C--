#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, ans = 0, temp = 0;
        unordered_set<char> us;
        while (right < s.size()) {
            if (us.count(s[right])) {
                while (s[left] != s[right]) {
                    us.erase(s[left]);
                    left++;
                }
                left++;
            } else {
                us.insert(s[right]);
            }
            temp = right - left + 1;
            ans = max(ans, temp);
            right++;
        }
        return ans;
    }
};