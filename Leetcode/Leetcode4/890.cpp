#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
private:
    bool isTrue(string& word, string& pattern) {
        unordered_map<char, char> um;
        for (int i = 0; i < word.size(); i++) {
            if (um.count(word[i])) {
                if (um[word[i]] != pattern[i]) 
                    return false;
            }
            else {
                um.insert({word[i], pattern[i]});
            }
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            if (isTrue(words[i], pattern) && isTrue(pattern, words[i]))
                ans.push_back(words[i]);
        }
        return ans;
    }
};