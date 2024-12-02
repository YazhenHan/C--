#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, bool> um;
    bool wordBreak(string s, int i, vector<string>& wordDict) {
        if (s.size() == i) return true;
        if (um.count(i)) return um[i];
        bool ans = false;
        for (const string & word : wordDict) {
            if (s.substr(i).find(word) == 0)
                ans |= wordBreak(s, i + word.size(), wordDict);
        }
        um[i] = ans;
        return ans;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        return wordBreak(s, 0, wordDict);
    }
};