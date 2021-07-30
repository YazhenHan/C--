#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> ans;
        int counts[201];
        for (int i = 0; i < 201; ++i)
            counts[i] = 0;
        for (auto num : nums)
            ++counts[num + 100];
        vector<pair<int, int>> forAns;
        for (int i = 0; i < 201; ++i)
            forAns.push_back({i, counts[i]});
        sort(forAns.begin(), forAns.end(), cmp);
        for (auto forans : forAns)
            for (int i = 0; i < forans.second; ++i)
                ans.push_back(forans.first);
        return ans;
    }
private:
    bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second == b.second ? a.first > b.first : a.second < b.second;
    }
};