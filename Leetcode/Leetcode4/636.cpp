#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> forAns;
        vector<int> ans(n, 0);
        int lid = stoi(logs.front().substr(0, logs.front().find_first_of(':')));
        bool lse = logs.front().substr(logs.front().find_first_of(':') + 1, 3) == "end" ? false : true;
        int ltime = stoi(logs.front().substr(logs.front().find_last_of(':') + 1));
        forAns.push(lid);
        for (int i = 1; i < logs.size(); i++) {
            int cid = stoi(logs[i].substr(0, logs[i].find_first_of(':')));
            bool cse = logs[i].substr(logs[i].find_first_of(':') + 1, 3) == "end" ? false : true;
            int ctime = stoi(logs[i].substr(logs[i].find_last_of(':') + 1));
            if (cse && lse) {
                ans[lid] += ctime - ltime;
                forAns.push(cid);
            }
            if (cse && !lse) {
                if (!forAns.empty())
                    ans[forAns.top()] += ctime - ltime - 1;
                forAns.push(cid);
            }
            if (!cse && lse) {
                ans[cid] += ctime - ltime + 1;
                forAns.pop();
            }
            if (!cse && !lse) {
                ans[cid] += ctime - ltime;
                forAns.pop();
            }
            lid = cid;
            lse = cse;
            ltime = ctime;
        }
        return ans;
    }
};