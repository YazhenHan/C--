#include <queue>
#include <unordered_set>

using namespace std;

class SmallestInfiniteSet {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> flags;
    int line;
public:
    SmallestInfiniteSet() {
        line = 1;
    }
    
    int popSmallest() {
        if (pq.empty())
            return line++;
        int ans = pq.top();
        pq.pop();
        flags.erase(flags.find(ans));
        return ans;
    }
    
    void addBack(int num) {
        if (!flags.count(num) && line > num) {
            pq.push(num);
            flags.insert(num);            
        }
    }
};