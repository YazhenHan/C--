#include <string>

using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int zero = 0, one = 0;
        for (auto c : s)
            c == '0' ? zero++ : one++;
        int ans = s[0] == '0' ? one + 1 : one - 1,
            left = s[0] == '0' ? 1 : 0, 
            right = s[0] == '0' ? one : one - 1;
        for (int i = 1; i < s.size() - 1; i++) {
            if (s[i] == '0') {
                left++;
            } else {
                right--;
            }
            ans = max(ans, left + right);
        }
        return ans;
    }
};