#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        vector<int> v;
        while (num != 0) {
            v.push_back(num % 10);
            num /= 10;
        }
        vector<int> v2 = v;
        sort(v2.begin(), v2.end());
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] == v2[i]) continue;
            for (int j = 0; j <= i; j++) {
                if (v[j] == v2[i]) {
                    int t = v[j];
                    v[j] = v[i];
                    v[i] = t;
                    break;
                }
            }
            break;
        }
        int ans = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            ans = ans * 10 + v[i];
        }
        return ans;
    }
};