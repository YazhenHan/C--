#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int, int>> vp;
        for (int i = 0; i < arr.size(); i++)
            vp.push_back({arr[i], i});
        sort(vp.begin(), vp.end());
        vector<int> ans(arr.size());
        int t = 1;
        for (int i = 0; i < vp.size(); i++) {
            if (i >= 1 && vp[i].first != vp[i - 1].first)
                t++;
            ans[vp[i].second] = t;
        }
        return ans;
    }
};