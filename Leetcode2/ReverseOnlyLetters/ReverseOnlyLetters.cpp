#include <string>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
        string ans;
        int right = S.size() - 1;
        while (right >= 0)
        {
            while (ans.size() < S.size() && !isalpha(S[ans.size()]))
                ans.push_back(S[ans.size()]);
            if (right >= 0 && isalpha(S[right]))
                ans.push_back(S[right]);
            right--;
        }
        while (ans.size() < S.size() && !isalpha(S[ans.size()]))
            ans.push_back(S[ans.size()]);
        return ans;
    }
};