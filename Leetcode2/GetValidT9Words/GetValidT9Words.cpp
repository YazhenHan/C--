#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    char m[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6',
                    '7', '7', '7', '7', '8', '8', '8', '9', '9', '9', '9'};
    bool isT(string num, string word) {
        if (num.size() != word.size())
            return false;
        for (size_t i = 0; i < word.size(); i++)
            if (m[word[i] - 'a'] != num[i])
                return false;
        return true;
    }
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        vector<string> ans;
        for (auto word : words)
            if (isT(num, word))
                ans.push_back(word);
        return ans;
    }
};