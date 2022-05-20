#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (int i = 0; i < intervals.size(); i++)
            m.insert({intervals[i][0], i});
        vector<int> ans;
        for (int i = 0; i < intervals.size(); i++) {
            int right = intervals[i][1];
            if (m.find(right) != m.end()) {
                ans.push_back(m[right]);
            }
            else {
                m.insert({right, -1});
                auto it = ++m.find(right);
                if (it != m.end())
                    ans.push_back(it->second);
                else
                    ans.push_back(-1);
                m.erase(--it);
            }
        }
        return ans;
    }
};