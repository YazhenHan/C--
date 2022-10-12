#include <vector>
#include <queue>

using namespace std;

// Out of time
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = nums.size() - 1; i >= 0; i--) {
            queue<int> t;
            while (!pq.empty() && pq.top() < nums[i]) {
                t.push(pq.top());
                pq.pop();
            }
            ans[i] = t.size();
            while (!t.empty()) {
                pq.push(t.front());
                t.pop();
            }
            pq.push(nums[i]);
        }
        return ans;
    }
};