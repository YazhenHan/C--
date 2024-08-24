#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char, int> um;
        for (int i = 0; i < s.size(); i++)
            um[s[i]] = i;
        int ans = 0;
        for (int i = 0; i < t.size(); i++)
            ans += abs(um[t[i]] - i);
        return ans;
    }
};