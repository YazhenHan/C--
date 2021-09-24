#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> flags(128, 0);
        for (auto c : s)
            flags[c]++;
        int ans = 0;
        for (auto flag : flags)
            if (flag % 2 != 0)
                ans++;
        return ans <= 1;
    }
};