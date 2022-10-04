#include <string>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int left = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                left++;
            } else {
                if (left > 0)
                    left--;
                else
                    ans++;
            }
        }
        return ans + left;
    }
};