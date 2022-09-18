#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<string, char> um;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 1; j <= words[i].size(); j++) {
                string temp = words[i].substr(0, j);
                um[temp]++;
            }
        }
        vector<int> ans(words.size());
        for (int i = 0; i < words.size(); i++) {
            for (int j = 1; j <= words[i].size(); j++) {
                string temp = words[i].substr(0, j);
                ans[i] += um[temp];
            }
        }
        return ans;
    }
};