#include <vector>
#include <algorithm>
#include <utility>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        vector<pair<int, int>> vp;
        for (int num : nums) {
            if (um.count(num)) {
                vp[um[num]].second++;
            } else {
                vp.push_back({num, 1});
                um.insert({num, vp.size() - 1});
            }
        }
        sort(vp.begin(), vp.end(), [](const pair<int, int> & p1, const pair<int, int> & p2) { return p1.second >= p2.second; });
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(vp[i].first);
        }
        return ans;
    }
};