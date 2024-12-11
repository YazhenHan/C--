#include <vector>
#include <set>
#include <utility>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second < b.second; // 按第二个元素排序
        };

        multiset<pair<int, int>, decltype(cmp)> sp(cmp);

        unordered_map<int, multiset<std::pair<int, int>, decltype(cmp)>::iterator> um;

        for (int i = 0; i < k; i++) {
            auto temp = sp.insert({i, nums[i]});
            um.insert({i, temp});
        }

        vector<int> ans;
        ans.push_back((*sp.rbegin()).second);

        for (int i = k; i < nums.size(); i++) {
            sp.erase(um[i - k]);
            auto temp = sp.insert({i, nums[i]});
            um.insert({i, temp});
            
            ans.push_back((*sp.rbegin()).second);
        }

        return ans;
    }
};