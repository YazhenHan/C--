#include <vector>
#include <utility>

using namespace std;

class MaxPQ
{
private:
    vector<pair<int, int>> pq;
    int N = 0;
    void exch(int i, int j) { auto temp = pq[i]; pq[i] = pq[j]; pq[j] = temp; }
    void swim(int k) { 
        while (k > 1 && pq[k / 2] < pq[k])
        {
            exch(k / 2, k);
            k = k /2;
        }
    }
    void sink(int k) {
        while (2 * k <= N)
        {
            int j = 2 * k;
            if (j < N && pq[j] < pq[j+1])
                j++;
            if (pq[k] >= pq[j])
                break;
            exch(k, j);
            k = j;
        }
    }
public:
    MaxPQ() { pq.push_back({}); }
    void insert(pair<int, int> v) { pq.push_back(v); swim(++N); }
    void delMax() {
        exch(1, N--);
        sink(1);
        pq.pop_back();
    }
    auto top() { return pq[1]; }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MaxPQ maxPQ;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            maxPQ.insert({nums[i], i});
            while (i - k >= maxPQ.top().second)
                maxPQ.delMax();
            if (i >= k - 1)
                res.push_back(maxPQ.top().first);
        }
        return res;
    }
};