#include <queue>

using namespace std;

class MovingAverage {
private:
    queue<int> q;
    double sum = 0;
    int size = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        return sum / q.size();
    }
};
