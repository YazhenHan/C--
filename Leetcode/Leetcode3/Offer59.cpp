#include <queue>
#include <deque>

using namespace std;

class MaxQueue {
private:
    queue<int> q;
    deque<int> d;

public:
    MaxQueue() {

    }
    
    int max_value() {
        if (q.size() == 0) return -1;
        return d.front();
    }
    
    void push_back(int value) {
        q.push(value);
        while (d.size() > 0 && d.back() < value)
            d.pop_back();
        d.push_back(value);
    }
    
    int pop_front() {
        if (q.size() == 0) return -1;
        int ans = q.front();
        if (ans == d.front())
            d.pop_front();
        q.pop();
        return ans;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */