#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> ans;
        for (int i = 0; i < mat.size(); ++i) {
            int temp = 0;
            for (auto n : mat[i]) temp += n;
            ans.push_back(pair(i, temp));
        }
        for (int i = 0; i < ans.size(); ++i) {
            auto temp = ans[i];
            int j = i - 1;
            for (; j >= 0; --j) {
                if (ans[j].second > temp.second)
                    ans[j + 1] = ans[j];
                else 
                    break;
            }
            ans[j + 1] = temp;
        }
        vector<int> a;
        for (int i = 0; i < k; ++i)
            a.push_back(ans[i].first);
        return a;
    }
};