#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> filter(26, false);
        for (auto c : allowed)
            filter[c - 'a'] = true;
        int ans = 0;
        for (auto && word : words) {
            bool flag = true;
            for (auto c : word)
                if (!filter[c - 'a']) {
                    flag = false;
                    break;
                }
            if (flag)
                ans++;
        }
        return ans;
    }
};