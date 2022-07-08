#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

struct SetHash {
    size_t operator()(const multiset<int>& s) const {
        hash<int> hasher;
        size_t seed = 0;
        for (int i : s) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_set<multiset<int>, SetHash> filter;
        vector<vector<int>> ans;
        ans.push_back({});
        for (int i = 0; i < nums.size(); i++) {
            auto f = filter;
            multiset<int> m;
            m.insert(nums[i]);
            if (!filter.count(m)) {
                filter.insert(m);
                ans.push_back(vector<int>(m.begin(), m.end()));
            }
            for (auto t : f) {
                t.insert(nums[i]);
                if (!filter.count(t)) {
                    filter.insert(t);
                    ans.push_back(vector<int>(t.begin(), t.end()));
                }
            }
        }
        return ans;
    }
};