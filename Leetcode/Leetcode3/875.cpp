#include <vector>
#include <queue>

using namespace std;



class Solution {
private:
    struct pile {
        int pilen, n;
        double pdn;
        bool operator < (const pile & p) const {
            return pdn < p.pdn;
        }
    };
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        priority_queue<pile> pq;
        for (auto && p : piles) {
            pile t;
            t.pilen = p;
            t.n = 1;
            t.pdn = (double)t.pilen / t.n;
            pq.push(t);
        }
        for (int i = piles.size(); i < h; i++) {
            auto t = pq.top();
            t.n = t.n + 1;
            t.pdn = (double)t.pilen / t.n;
            pq.pop();
            pq.push(t);
        }
        return ceil(pq.top().pdn);
    }
};