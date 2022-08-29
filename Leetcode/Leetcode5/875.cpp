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
    // Out of time
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

class Solution {
private:
    long getTime(const vector<int>& piles, int speed) {
        long time = 0;
        for (auto pile : piles)
            time += (pile + speed - 1) / speed;
        return time;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end()), ans = high;
        while (low < high) {
            int speed = (high - low) / 2 + low;
            long time = getTime(piles, speed);
            if (time <= h) {
                ans = speed;
                high = speed;
            } else {
                low = speed + 1;
            }
        }
        return ans;
    }
};