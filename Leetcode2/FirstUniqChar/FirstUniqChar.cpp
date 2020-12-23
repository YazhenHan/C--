#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int filter[26] = {0};
        for (auto c : s)
            filter[c - 'a']++;
        for (int i = 0; i < s.size(); i++)
            if (filter[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};