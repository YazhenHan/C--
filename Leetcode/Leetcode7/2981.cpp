#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> vv(26, vector<int>(3, -1));
        vv[s[0] - 'a'][0] = 1;
        int t = 1;
        int ans = -1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                t++;
            } else {
                t = 1;
            }
            if (t >= vv[s[i] - 'a'][0]) {
                vv[s[i] - 'a'][2] = vv[s[i] - 'a'][1];
                vv[s[i] - 'a'][1] = vv[s[i] - 'a'][0];
                vv[s[i] - 'a'][0] = t;
            } else if (t >= vv[s[i] - 'a'][1]) {
                vv[s[i] - 'a'][2] = vv[s[i] - 'a'][1];
                vv[s[i] - 'a'][1] = t;
            } else if (t >= vv[s[i] - 'a'][2]) {
                vv[s[i] - 'a'][2] = t;
            }
            ans = max(ans, vv[s[i] - 'a'][2]);
        }
        return ans;
    }
};