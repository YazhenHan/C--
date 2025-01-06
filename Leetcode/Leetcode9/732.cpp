#include <unordered_map>

using namespace std;

class MyCalendarThree {
private:
    unordered_map<int, pair<int, int>> tree;
    void update(int startTime, int endTime, int l, int r, int idx, int val) {
        if (r < startTime || endTime < l) return;
        if (startTime <= l && r <= endTime) {
            tree[idx].first += val;
            tree[idx].second += val;
            return;
        }
        int mid = (l + r) >> 1;
        update(startTime, endTime, l, mid, 2 * idx, val);
        update(startTime, endTime, mid + 1, r, 2 * idx + 1, val);
        tree[idx].first = tree[idx].second + max(tree[2 * idx].first, tree[2 * idx + 1].first);
    }

public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        update(startTime, endTime - 1, 0, 1e9, 1, 1);
        return tree[1].first;
    }
};