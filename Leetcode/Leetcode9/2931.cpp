#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        priority_queue<pair<int, pair<int, int>>> pq;
        for (int i = 0; i < values.size(); i++) pq.push({values[i][0], {i, 0}});
        long long cnt = values.size() * values.back().size();
        long long ans = 0;
        while (cnt > 0) {
            auto temp = pq.top();
            pq.pop();
            ans += temp.first * cnt;
            if (temp.second.second + 1 < values.back().size())
                pq.push({values[temp.second.first][temp.second.second + 1], {temp.second.first, temp.second.second + 1}});
            cnt--;
        }
        return ans;
    }
};