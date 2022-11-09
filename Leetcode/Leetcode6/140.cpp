#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, vector<string>> ans;
    unordered_set<string> wordSet;
    void backtrack(const string& s, int index) {
        if (!ans.count(index)) {
            if (index == s.size()) {
                ans[index] = {""};
                return;
            }
            ans[index] = {};
            for (int i = index + 1; i <= s.size(); i++) {
                string word = s.substr(index, i - index);
                if (wordSet.count(word)) {
                    backtrack(s, i);
                    for (const string& succ : ans[i]) {
                        ans[index].push_back(succ.empty() ? word : word + " " + succ);
                    }
                }
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDick) {
        wordSet = unordered_set(wordDick.begin(), wordDick.end());
        backtrack(s, 0);
        return ans[0];
    }
};