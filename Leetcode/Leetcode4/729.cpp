#include <set>
#include <utility>

using namespace std;

class MyCalendar {
private:
    set<pair<int, int>> sp;
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        if (sp.empty()) { 
            sp.insert({start, end});
            return true;
        }
        for (auto a = sp.begin(); a != sp.end(); a++) {
            auto b = a;
            b++;
            if ((a == sp.begin() && a->first >= end) || 
                (b == sp.end() && a->second <= start) || 
                (b != sp.end() && a->second <= start && b->first >= end)) {
                sp.insert({start, end});
                return true;
            }
        }
        return false;
    }
};