#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int getKthMagicNumber(int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_set<int> us;
        pq.push(1);
        us.insert(1);
        for (int i = 1; i < k; i++) {
            int t = pq.top();
            if ((long)t * 3 < INT32_MAX && !us.count(t * 3)) {
                pq.push(t * 3);
                us.insert(t * 3);
            }
            if ((long)t * 5 < INT32_MAX && !us.count(t * 5)) {
                pq.push(t * 5);
                us.insert(t * 5);
            }
            if ((long)t * 7 < INT32_MAX && !us.count(t * 7)) {
                pq.push(t * 7);
                us.insert(t * 7);
            }
            pq.pop();
        }
        return pq.top();
    }
};