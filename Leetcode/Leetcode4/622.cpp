#include <vector>

using namespace std;

class MyCircularQueue {
private:
    vector<int> q;
    int h, e;
public:
    MyCircularQueue(int k) {
        q.resize(k + 1);
        h = 0;
        e = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        q[e] = value;
        e = (e + 1) % q.size();
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        h = (h + 1) % q.size();
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : q[h];
    }
    
    int Rear() {
        return isEmpty() ? -1 : q[(e - 1 + q.size()) % q.size()];
    }
    
    bool isEmpty() {
        return h == e;
    }
    
    bool isFull() {
        return (e + 1) % q.size() == h;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */