#include <set>

using namespace std;

class ExamRoom {
private:
    int n;
    set<int> s;
public:
    ExamRoom(int n) {
        this->n = n;
    }
    
    int seat() {
        if (s.empty()) {
            s.insert(0);
            return 0;
        }

        int distance = INT32_MIN, ans;
        auto left = s.begin(), right = s.begin();
        right++;
        while (right != s.end()) {
            if ((*right - *left) / 2 > distance) {
                distance = (*right - *left) / 2;
                ans = *left + distance;
            }
            left++;
            right++;
        }
        if (*s.begin() - 0 >= distance) {
            distance = *s.begin() - 0;
            ans = 0;
        }
        if (n - 1 - *(--s.end()) > distance) {
            distance = n - 1 - *(--s.end());
            ans = n - 1;
        }
        s.insert(ans);
        return ans;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};