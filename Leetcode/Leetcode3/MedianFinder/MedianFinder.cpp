#include <queue>

using namespace std;

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (g.size() == 0)
            g.push(num);
        else if (num >= g.top())
            l.push(num);
        else
            g.push(num);
        if (g.size() - l.size() == 2) {
            l.push(g.top());
            g.pop();
        }
        else if (l.size() - g.size() == 2) {
            g.push(l.top());
            l.pop();
        }
    }
    
    double findMedian() {
        if (g.size() == l.size())
            return (g.top() + l.top()) / 2.0;
        if (g.size() > l.size())
            return g.top();
        return l.top();
    }
private:
    priority_queue<int, vector<int>, less<int>> g;
    priority_queue<int, vector<int>, greater<int>> l;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */