#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<int, int> um;
    int recursive(int x) {
        if (um.count(x)) return um[x];
        int ans = (x % 2 ? recursive(3 * x + 1) : recursive(x / 2)) + 1;
        um[x] = ans;
        return ans;
    }
    int getKth(int lo, int hi, int k) {
        um[1] = 0;
        vector<int> v(hi - lo + 1);
        for (int i = 0; i < v.size(); i++) v[i] = lo + i;
        sort(v.begin(), v.end(), [&](int x, int y) {
            return recursive(x) < recursive(y) || (recursive(x) == recursive(y) && x < y);
        });
        return v[k - 1];
    }
};