#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> keys;
        for (auto c : key) {
            if (c == ' ' || keys.count(c)) continue;
            keys.insert({c, keys.size() + 'a'});
        }
        string ans;
        for (auto c : message) {
            if (c == ' ')
                ans.push_back(' ');
            else
                ans.push_back(keys[c]);
        }
        return ans;
    }
};