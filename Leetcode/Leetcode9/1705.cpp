#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        // auto comp = [](const pair<int, int> & p1, const pair<int, int> & p2) {
            // return p1.first < p2.first;
        // };
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int ans;
        for (int i = 0; i < apples.size(); i++) {
            pq.push({i + days[i], apples[i]});
            while (!pq.empty() && pq.top().first <= i) pq.pop();
            if (!pq.empty()) {
                pair<int, int> p = pq.top();
                pq.pop();
                if (p.second > 1) pq.push({p.first, p.second - 1});
                ans++;
            }
        }
        int i = apples.size();
        while (!pq.empty()) {
            while (!pq.empty() && pq.top().first <= i) pq.pop();
            if (!pq.empty()) {
                ans += min(pq.top().first, pq.top().second);
                i += min(pq.top().first, pq.top().second);
                pq.pop();
            }
        }
        return ans;
    }
};