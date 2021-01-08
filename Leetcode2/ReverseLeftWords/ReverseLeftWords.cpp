#include <string>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string ans;
        for (int i = n; i < s.size(); i++)
            ans.push_back(s[i]);
        for (int i = 0; i < n; i++)
            ans.push_back(s[i]);
        return ans;
    }
};