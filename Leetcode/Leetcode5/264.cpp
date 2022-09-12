#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> pq;
        unordered_set<long> us;
        pq.push(1);
        us.insert(1);
        for (int i = 1; i < n; i++) {
            int t = pq.top();
            if (!us.count(t * 2l)) {
                pq.push(t * 2l);
                us.insert(t * 2l);
            }
            if (!us.count(t * 3l)) {
                pq.push(t * 3l);
                us.insert(t * 3l);
            }
            if (!us.count(t * 5l)) {
                pq.push(t * 5l);
                us.insert(t * 5l);
            }
            pq.pop();
        }
        return pq.top();
    }
};