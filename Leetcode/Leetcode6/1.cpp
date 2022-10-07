#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minNumBooths(vector<string>& demand) {
        int ans = 0;
        vector<int> filter(26, 0), filter2(26, 0);
        for (int i = 0; i < demand.size(); i++) {
            for (int j = 0; j < demand[i].size(); j++) {
                if (filter[demand[i][j] - 'a'] <= 0) {
                    filter2[demand[i][j] - 'a']++;
                    ans++;
                } else {
                    filter[demand[i][j] - 'a']--;
                }
            }
            filter = filter2;
        }
        return ans;
    }
};