#include <string>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char a = 0;
        for (auto c : s)
            a ^= c;
        for (auto c : t)
            a ^= c;
        return a;
    }
};