#include <string>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        string l = first.size() > second.size() ? first : second;
        string s = first.size() > second.size() ? second : first;
        if (l.size() - s.size() >= 2)
            return false;
        int i = 0, j = 0, ans = 0;
        while (i < s.size() && j < l.size()) {
            if (s[i] != l[j]) {
                j++;
                if (l.size() == s.size()) i++;
                ans++;
                continue;
            }
            i++;
            j++;
        }
        return ans <= 1;
    }
};