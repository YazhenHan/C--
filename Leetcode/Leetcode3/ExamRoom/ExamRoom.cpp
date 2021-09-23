#include <set>

using namespace std;

class ExamRoom {
private:
    set<int> s;
    int n;
public:
    ExamRoom(int n) {
        this->n = n;
    }
    
    int seat() {
        if (s.size() == 0) {
            s.insert(0);
            return 0;
        }
        int ans = 0;
        int a = 0;
        int l = 0;
        for (auto c : s) {
            int t = (l + c) / 2;
            if (min(t - l, c - t) > a) {
                a = min(t - l, c - t);
                ans = t;
            }
            l = c;
        }
        if (*s.begin() >= n - *(--s.end()) - 1 && *s.begin() >= a)
            ans = 0;
        else if (n - *(--s.end()) - 1 > *s.begin() && n - *(--s.end()) - 1 > a)
            ans = n - 1;
        s.insert(ans);
        return ans;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};
