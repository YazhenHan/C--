#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0) {
            return ans;
        } else if (k > 0) {
            int temp = 0;
            for (int i = 1; i <= k && i < n; i++)
                temp += code[i];
            for (int i = 0; i < n; i++) {
                ans[i] = temp;
                temp -= code[(i + 1) % n];
                temp += code[(i + k + 1) % n];
            }
            return ans;
        } else {
            int temp = 0;
            for (int i = n - 1; i >= 0 && i > n - 1 + k; i--)
                temp += code[i];
            for (int i = 0; i < n; i++) {
                ans[i] = temp;
                temp += code[i];
                temp -= code[(i + k + n) % n];
            }
            return ans;
        }
    }
};