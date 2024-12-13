#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return !(a.first < b.first || (a.first == b.first && a.second < b.second));
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        for (int i = 0; i < k; i++) {
            auto temp = pq.top();
            nums[temp.second] *= multiplier;
            pq.pop();
            pq.push({nums[temp.second], temp.second});
        }
        return nums;
    }
};