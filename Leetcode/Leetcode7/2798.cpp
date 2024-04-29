#include <vector>

using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0;
        for (auto hour : hours) {
            if (hour >= target)
                ans++;
        }
        return ans;
    }
};