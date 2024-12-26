#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_set<string> us;
        for (int i = 0; i + 1 < s.size(); i++) {
            us.insert(s.substr(i, 2));
        }
        reverse(s.begin(), s.end());
        for (int i = 0; i + 1 < s.size(); i++) {
            if (us.count(s.substr(i, 2)))
                return true;
        }
        return false;
    }
};