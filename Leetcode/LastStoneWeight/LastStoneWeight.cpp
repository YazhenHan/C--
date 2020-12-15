#include <vector>

using namespace std;

class Solution {
private:
    std::vector<int> pq;
    int N = 0;
    void exch(int i, int j) { int temp = pq[i]; pq[i] = pq[j]; pq[j] = temp; }
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
    void insert(int v) { pq[++N] = v; swim(N); }
    int delMax() {
        int max = pq[1];
        exch(1, N--);
        sink(1);
        return max;
    }
public:
    int lastStoneWeight(vector<int>& stones) {
        pq.resize(stones.size() + 1);
        for (auto stone : stones)
            insert(stone);
        while (N > 1)
        {
            int temp1 = delMax();
            int temp2 = delMax();
            if (temp1 != temp2)
                insert(temp1 - temp2);
        }
        return delMax();
    }
};