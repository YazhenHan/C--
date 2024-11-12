#include <string>

using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0, n0 = 0, n1 = 0, left = 0, right = 0;
        while (right < s.size()) {
            if (s[right] == '0') n0++;
            else n1++;
            while (left < right && n1 > k && n0 > k) {
                if (s[left] == '0') n0--;
                else n1--;
                left++;
            }
            right++;
            ans += right - left;
        }
        return ans;
    }
};