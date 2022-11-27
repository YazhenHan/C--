#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    bool isLegal(string & s, string & word) {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            int ti = i, tj = j;
            while (i < s.size() && s[i] == word[tj])
                i++;
            while (j < word.size() && s[ti] == word[j])
                j++;
            if ((i - ti < j - tj) || (i - ti > j - tj && i - ti < 3) || (ti == i && tj == j))
                return false;
        }
        return i == s.size() && j == word.size() && i >= j;
    }
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for (auto & word : words) {
            if (isLegal(s, word))
                ans++;
        }
        return ans;
    }
};