#include <string>

using namespace std;

class Solution {
public:
    int minimumBuckets(string hamsters) {
        int ans = 0;
        for (int i = 0; i < hamsters.size(); i++) {
            if (hamsters[i] == 'H') {
                if (i - 1 >= 0 && hamsters[i - 1] == 'B') {
                    continue;
                } else if (i + 1 < hamsters.size() && hamsters[i + 1] == '.') {
                    hamsters[i + 1] = 'B';
                    ans++;
                } else if (i - 1 >= 0 && hamsters[i - 1] == '.') {
                    hamsters[i - 1] = 'B';
                    ans++;
                } else {
                    return -1;
                }
            }
        }
        return ans;
    }
};