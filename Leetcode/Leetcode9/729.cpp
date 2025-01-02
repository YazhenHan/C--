#include <set>

using namespace std;

class MyCalendar {
private:
    set<pair<int, int>> sp;
public:
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto it = sp.lower_bound({endTime, 0});
        if (it == sp.begin() || (--it)->second <= startTime) {
            sp.insert({startTime, endTime});
            return true;
        }
        return false;
    }
};
