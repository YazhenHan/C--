#include <string>

using namespace std;

class Solution {
public:
    int countTime(string time) {
        int ans = 1;
        if (time[1] == '?') {
            if (time[0] == '?')
                ans *= 24;
            else if (time[0] <= '1')
                ans *= 10;
            else if (time[0] == '2')
                ans *= 4;
        } else {
            if (time[1] <= '3' && time[0] == '?')
                ans *= 3;
            else if (time[1] > '3' && time[0] == '?')
                ans *= 2;
        }
        if (time[3] == '?')
            ans *= 6;
        if (time[4] == '?')
            ans *= 10;
        return ans;
    }
};