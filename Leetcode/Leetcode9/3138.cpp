#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minAnagramLength(string s) {
        unordered_set<char> us;
        for (char c : s) us.insert(c);
        for (int skip = us.size(); skip <= s.size(); skip++) {
            if (s.size() % skip != 0) continue;
            unordered_map<char, int> um;
            unordered_set<char> temp = us;
            for (int i = 0; i < skip; i++) {
                um[s[i]]++;
                temp.erase(s[i]);
            }
            if (!temp.empty()) continue;

            bool flag = true;
            for (int i = skip; i < s.size(); i += skip) {
                unordered_map<char, int> temp2 = um;
                for (int j = 0; j < skip; j++) {
                    temp2[s[i + j]]--;
                    if (!temp2[s[i + j]]) temp2.erase(s[i + j]);
                }
                if (!temp2.empty()) {
                    flag = false;
                    break;
                }
            }
            if (flag) return skip;
        }

        return s.size();
    }
};