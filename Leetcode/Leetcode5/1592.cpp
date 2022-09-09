#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reorderSpaces(string text) {
        int sn = 0, wn = 0, left = 0, right = 0;
        vector<string> v;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') sn++;
            if (i == text.size() - 1 && text[i] != ' ' || text[i] != ' ' && text[i + 1] == ' ') wn++;
            if (i == 0 && text[i] != ' ' || text[i] != ' ' && text[i - 1] == ' ') left = i;
            if (i == text.size() - 1 && text[i] != ' ' || text[i] != ' ' && text[i + 1] == ' ') {
                right = i;
                v.push_back(text.substr(left, right - left + 1));
            }
        }
        int msn = wn == 1 ? 0 : sn / (wn - 1), lsn = sn - (msn *( v.size() - 1));
        string ans;
        for (int i = 0; i < v.size(); i++) {
            ans += v[i];
            if (i != v.size() - 1)
                ans += string(msn, ' ');
        }
        ans += string(lsn, ' ');
        return ans;
    }
};