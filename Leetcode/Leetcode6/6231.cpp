#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int left_right = candidates - 1, right_left = max(candidates, (int)costs.size() - candidates);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> left, right;
        left.push({INT32_MAX, INT32_MAX});
        right.push({INT32_MAX, INT32_MAX});
        for (int i = 0; i <= left_right; i++)
            left.push({costs[i], i});
        for (int i = right_left; i < costs.size(); i++)
            right.push({costs[i], i});
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            if (left.top() < right.top()) {
                ans += left.top().first;
                left.pop();
                if (left_right + 1 != right_left) {
                    left.push({costs[left_right + 1], left_right + 1});
                    left_right++;
                }
            } else {
                ans += right.top().first;
                right.pop();
                if (right_left - 1 != left_right) {
                    right.push({costs[right_left - 1], right_left - 1});
                    right_left--;
                }
            }
        }
        return ans;
    }
};