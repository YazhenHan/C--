#include <queue>
#include <vector>

using namespace std;


class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> pqGreat;
    priority_queue<int, vector<int>, greater<int>> pqLess;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pqGreat.push(num);
        while (pqGreat.size() > pqLess.size()) {
            pqLess.push(pqGreat.top());
            pqGreat.pop();
        }
        while (pqLess.size() > pqGreat.size()) {
            pqGreat.push(pqLess.top());
            pqLess.pop();
        }
    }
    
    double findMedian() {
        if ((pqGreat.size() + pqLess.size()) % 2 == 0) {
            return (pqGreat.top() + pqLess.top()) / 2.0;
        }
        else
            return pqGreat.top();
    }
};