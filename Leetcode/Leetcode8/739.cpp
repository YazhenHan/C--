#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int, int>> s;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!s.empty() && s.top().first < temperatures[i]) {
                ans[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.push({temperatures[i], i});
        }
        return ans;
    }
};