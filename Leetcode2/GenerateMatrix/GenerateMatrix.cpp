#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;
    int m;
    int a = 1;
    void forAns(int k) {
        for (int j = k; j <= m - k - 1; j++, a++)
            ans[k][j] = a;
        for (int i = k + 1; i <= m - k - 1; i++, a++)
            ans[i][m - k - 1] = a;
        for (int j = m - k - 2; m - k - 1 != k && j >= k; j--, a++)
            ans[m - k - 1][j] = a;
        for (int i = m - k - 2; k != m - k - 1 && i > k; i--, a++)
            ans[i][k] = a;
    }
public:
    vector<vector<int>> generateMatrix(int n) {
        ans.resize(n);
        for (auto &a : ans)
            a.resize(n);
        m = n;
        for (int i = 0; i <= min(ceil(m / 2.0 - 1), ceil(n / 2.0 - 1)); i++)
            forAns(i);
        return ans;
    }
};