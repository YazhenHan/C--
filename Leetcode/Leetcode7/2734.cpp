#include <string>

using namespace std;

class Solution {
public:
    string smallestString(string s) {
        int i = 0;
        while (i < s.size() && s[i] == 'a') i++;
        if (i == s.size()) s[i - 1] = 'z';
        while (i < s.size() && s[i] != 'a') s[i++] -= 1;
        return s;
    }
};