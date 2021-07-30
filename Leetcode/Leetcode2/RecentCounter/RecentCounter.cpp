#include <queue>

using namespace std;

class RecentCounter
{
private:
    queue<int> forAns;
public:
    RecentCounter() {

    }
    int ping(int t) {
        forAns.push(t);
        while (forAns.front() < t - 3000)
            forAns.pop();
        return forAns.size();
    }
};