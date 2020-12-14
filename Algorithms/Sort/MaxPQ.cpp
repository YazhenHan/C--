#include <vector>
#include <iostream>
#include "../../Tools/Tools.hpp"

class MaxPQ
{
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
    void sink(int k, int N) {
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
    MaxPQ(int maxN) { pq.resize(maxN + 1); }
    MaxPQ(std::vector<int> pq) {
        this->pq.resize(pq.size() + 1);
        for (auto i : pq)
            this->pq[++N] = i;
    }
    bool isEmpty() { return N == 0; }
    int size() { return N; }
    void insert(int v) { pq[++N] = v; swim(N); }
    int delMax() {
        int max = pq[1];
        exch(1, N--);
        sink(1);
        return max;
    }
    void sort() {
        for (int k = N / 2; k >= 1; k--)
            sink(k, N);
        while (N > 1)
        {
            exch(1, N--);
            sink(1, N);
        }
    }
};