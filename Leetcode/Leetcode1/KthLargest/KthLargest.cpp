#include <vector>
#include <iostream>

using namespace std;

class KthLargest {
private:
    vector<int> pq;
    int N = 0;
    int min;
    void exch(int i, int j) { int temp = pq[i]; pq[i] = pq[j]; pq[j] = temp; }
    void swim(int k) { 
        while (k > 1 && pq[k / 2] > pq[k])
        {
            exch(k / 2, k);
            k = k /2;
        }
    }
    void sink(int k) {
        while (2 * k <= N)
        {
            int j = 2 * k;
            if (j < N && pq[j] > pq[j+1])
                j++;
            if (pq[k] <= pq[j])
                break;
            exch(k, j);
            k = j;
        }
    }
    void insert(int v) { pq[++N] = v; swim(N); min = pq[1]; }
    void delMax() {
        if (N == 0)
            return;
        exch(1, N--);
        sink(1);
    }
public:
    KthLargest(int k, vector<int>& nums) {
        pq.resize(k + 1);
        int i = 0;
        while (i < k && i < nums.size())
        {
            insert(nums[i]);
            i++;
        }
        while (i < nums.size())
        {
            if (nums[i] > min)
            {
                delMax();
                insert(nums[i]);
            }
            i++;
        }
    }
    
    int add(int val) {
        if (N < pq.size() - 1)
            insert(val);
        else if (val > min)
        {
            delMax();
            insert(val);
        }
        return min;
    }
};