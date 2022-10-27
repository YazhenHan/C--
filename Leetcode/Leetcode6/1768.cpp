#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        string ans;
        while (i < word1.size() && i < word2.size()) {
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
            i++;
        }
        if (i < word1.size())
            ans.append(word1.substr(i));
        else
            ans.append(word2.substr(i));
        return ans;
    }
};