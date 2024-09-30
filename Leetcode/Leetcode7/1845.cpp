#include <queue>

using namespace std;

class SeatManager {
private:
    struct MinHeap {
        bool operator()(int a, int b) {
            return a > b; // 反转比较以形成最小堆
        }
    };
    priority_queue<int, std::vector<int>, MinHeap> minHeap;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i++)
            minHeap.push(i);
    }
    
    int reserve() {
        int ans = minHeap.top();
        minHeap.pop();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        minHeap.push(seatNumber);
    }
};