#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    struct temp {
        int a;
        int b;
    };
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<temp> q;
        for (int i = 0; i < tickets.size(); i++) {
            temp t;
            t.a = tickets[i];
            t.b = (i == k ? 1 : 0);
            q.push(t);
        }
        int ans = 0;
        while (!q.empty()) {
            temp t = q.front();
            q.pop();
            t.a--;
            ans++;
            if (t.a != 0) q.push(t);
            else if (t.b == 1) break;
        }
        return ans;
    }
};