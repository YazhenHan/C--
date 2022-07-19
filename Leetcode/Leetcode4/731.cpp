#include <vector>

using namespace std;

class MyCalendarTwo {
private:
    vector<pair<int, int>> vp;
    vector<pair<int, int>> vp2;
public:
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        for (auto& p : vp)
            if (p.first < end && p.second > start)
                return false;
        
        for (auto& p : vp2)
            if (p.first < end && p.second > start)
                vp.emplace_back(max(p.first, start), min(p.second, end));
        vp2.emplace_back(start, end);
        return true;
    }
};