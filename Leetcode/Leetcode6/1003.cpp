#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 3 != 0) return false;
        while (s.size() > 0) {
            string st;
            int i = 0;
            while (i < s.size()) {
                if (i < s.size() && s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                    i += 3;
                    continue;
                }
                st.push_back(s[i]);
                i++;
            }
            if (st.size() == s.size()) return false;
            s = st;
        }
        return true;
    }
};