#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> flags(26, 0);
        int ans = 0;
        for (auto c : sentence) {
            if (flags[c - 'a'] == 0)
                ans++;
            flags[c - 'a']++;
        }
        return ans >= 26;
    }
};