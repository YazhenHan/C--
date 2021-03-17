#include <string>

using namespace std;

class Solution {
private:
    int ans = 0;
    void numD(string s, string t, int m, int n) {
        if (n == t.size())
        {
            ans++;
        }
        for (int i = m; i < s.size(); i++)
        {
            if (s[i] == t[n])
            {
                numD(s, t, i + 1, n + 1);
            }
        }
    }
public:
    int numDistinct(string s, string t) {
        numD(s, t, 0, 0);
        return ans;
    }
};