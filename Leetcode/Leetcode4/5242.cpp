#include <string>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        string ans = "";
        vector<pair<bool, bool>> flags(26, {false, false});
        for (auto c : s) {
            if (c >= 'A' && c <= 'Z') {
                flags[c - 'A'].first = true;
                if (flags[c - 'A'].first && flags[c - 'A'].second) {
                    if (ans.size() == 0) ans.push_back(c);
                    else if (c > ans[0]) ans[0] = c; 
                }
            }
            else {
                flags[c - 'a'].second = true;
                if (flags[c - 'a'].first && flags[c - 'a'].second) {
                    if (ans.size() == 0) ans.push_back(c - 32);
                    else if (c - 32 > ans[0]) ans[0] = c - 32; 
                }
            }
        }
        return ans;
    }
};