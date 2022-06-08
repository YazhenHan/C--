#include <vector>

using namespace std;

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> mm, ans;
        for (int i = 1; i <= m; i++)
            mm.push_back(i);
        for (int i = 0; i < queries.size(); i++) {
            if (mm[0] == queries[i]) { ans.push_back(0); continue; }
            int temp1 = mm[1], temp2 = mm[0], j = 1;
            for (; temp2 != queries[i]; j++) {
                temp1 = mm[j];
                mm[j] = temp2;
                temp2 = temp1;
            }
            mm[0] = queries[i];
            ans.push_back(j - 1);
        }
        return ans;
    }
};