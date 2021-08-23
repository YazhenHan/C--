#include <vector>

using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n <= 1) return n;
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            if (i % 2 == 0)
                v.push_back(v[i / 2]);
            else
                v.push_back(v[i / 2] + v[i / 2 + 1]);
            if (v.back() > ans) ans = v.back();
        }
        return ans;
    }
};