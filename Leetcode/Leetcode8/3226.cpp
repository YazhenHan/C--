#include <string>

using namespace std;

class Solution {
public:
    int minChanges(int n, int k) {
        string nn;
        string kk;
        while (n != 0) {
            nn.push_back(n % 2 + '0');
            n /= 2;
        }
        while (k != 0) {
            kk.push_back(k % 2 + '0');
            k /= 2;
        }
        int ans = 0, i = 0;
        while (i < nn.size() && i < kk.size()) {
            if (nn[i] == '1' && kk[i] == '0') ans++;
            else if (nn[i] == '0' && kk[i] == '1') return -1;
            i++;
        }
        while (i < nn.size()) {
            if (nn[i] == '1') ans++;
            i++;
        }
        while (i < kk.size()) {
            if (kk[i] == '1') return -1;
            i++;
        }
        return ans;
    }
};