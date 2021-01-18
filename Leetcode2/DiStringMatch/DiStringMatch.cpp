#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans;
        ans.push_back(0);
        int ma = 0, mi = 0;
        for (auto c : S)
            if (c == 'I')
                ans.push_back(++ma);
            else
                ans.push_back(--mi);
        for (auto a : ans)
            a += -mi;
        return ans;
    }
};