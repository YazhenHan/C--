#include <vector>

using namespace std;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ans = 0;
        while (amount[0] > 0 || amount[1] > 0 || amount[2] > 0) {
            if (amount[0] >= amount[1] && amount[0] >= amount[2]) {
                if (amount[1] >= amount[2] && amount[1] > 0) amount[1]--;
                else if (amount[2] >= amount[1] && amount[2] > 0) amount[2]--;
                amount[0]--;
            } else if (amount[1] >= amount[0] && amount[1] >= amount[2]) {
                if (amount[0] >= amount[2] && amount[0] > 0) amount[0]--;
                else if (amount[2] >= amount[0] && amount[2] > 0) amount[2]--;
                amount[1]--;
            } else if (amount[2] >= amount[0] && amount[2] >= amount[1]) {
                if (amount[0] >= amount[1] && amount[0] > 0) amount[0]--;
                else if (amount[1] >= amount[0] && amount[1] > 0) amount[1]--;
                amount[2]--;
            } 
            ans++;
        }
        return ans;
    }
};