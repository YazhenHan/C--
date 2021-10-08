#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> olded;
        unordered_set<string> ans;
        for (int i = 0; i + 10 <= s.size(); i++) {
            string t(s.begin() + i, s.begin() + i + 10);
            if (olded.find(t) == olded.end()) olded.insert(t);
            else ans.insert(t);
        }
        return vector<string>(ans.begin(), ans.end());
    }
};