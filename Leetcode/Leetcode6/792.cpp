#include <vector>
#include <string>

using namespace std;

// Out of time.
class Solution {
private:
    bool isLegal(const string & s, const string & word) {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] == word[j])
                j++;
            i++;
        }
        return j == word.size();
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        for (const auto & word : words) {
            if (isLegal(s, word))
                ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);
        for (int i = 0; i < s.size(); i++)
            pos[s[i] - 'a'].push_back(i);
        int ans = words.size();
        for (const auto & word : words) {
            if (word.size() > s.size()) {
                ans--;
                continue;
            }
            int p = -1;
            for (char c : word) {
                auto &ps = pos[c - 'a'];
                auto it = upper_bound(ps.begin(), ps.end(), p);
                if (it == ps.end()) {
                    ans--;
                    break;
                }
                p = *it;
            }
        }
        return ans;
    }
};