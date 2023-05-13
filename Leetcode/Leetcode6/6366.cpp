#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto detail : details) {
            if (detail[11] == '6' && detail[12] > '0' || detail[11] > '6')
                ans++;
        }
        return ans;
    }
};