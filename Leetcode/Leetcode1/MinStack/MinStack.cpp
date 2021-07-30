#include <vector>

using namespace std;

class MinStack {
private:
    vector<int> res;
    vector<int> resres;
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        res.push_back(x);
        if (resres.empty() || x <= resres.back())
            resres.push_back(x);
    }
    
    void pop() {
        if (resres.back() == res.back())
            resres.pop_back();
        res.pop_back();
    }
    
    int top() {
        return res.back();
    }
        
    int min() {
        return resres.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */