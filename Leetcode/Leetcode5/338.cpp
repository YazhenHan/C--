#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 1; i <= n; i++) {
            if (n % 2 == 0)
                ans.push_back(ans[n / 2]);
            else
                ans.push_back(ans.back() + 1);
        }
        return ans;
    }
};