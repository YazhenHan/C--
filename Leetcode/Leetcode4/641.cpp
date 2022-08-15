#include <vector>

using namespace std;

class MyCircularDeque {
private:
    vector<int> dq;
    int h;
    int t;
    int amount;
public:
    MyCircularDeque(int k) {
        dq.resize(k);
        h = 0;
        t = k - 1;
        amount = 0;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        dq[h] = value;
        h = (h + 1) % dq.size();
        amount++;
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        dq[t] = value;
        t = (t - 1 + dq.size()) % dq.size();
        amount++;
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        h = (h - 1 + dq.size()) % dq.size();
        amount--;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        t = (t + 1) % dq.size();
        amount--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()) return -1;
        return dq[(h - 1 + dq.size()) % dq.size()];
    }
    
    int getRear() {
        if (isEmpty()) return -1;
        return dq[(t + 1) % dq.size()];
    }
    
    bool isEmpty() {
        return amount == 0;
    }
    
    bool isFull() {
        return amount == dq.size();
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */