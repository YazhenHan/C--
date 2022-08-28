#include <string>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string ans;
        int t = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '*') {
                t++;
            }
            else {
                if (t == 0) {
                    ans.push_back(s[i]);
                } else {
                    t--;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};