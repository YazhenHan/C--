#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        unordered_set<int> us;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                us.insert(i);
                for (int j = i - 1; j >= 0; j--) {
                    if (us.count(j)) continue;
                    us.insert(j);
                    break;
                }
            }
        }
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (us.count(i)) continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
};