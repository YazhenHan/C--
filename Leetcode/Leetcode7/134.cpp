#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0, n = gas.size();
        while (i < n) {
            int amount = 0, j = 0;
            while (j < n) {
                int temp = (i + j) % n;
                amount += gas[temp] - cost[temp];
                if (amount < 0) break;
                j++;
            }
            if (j == n) return i;
            else i += j + 1;
        }
        return -1;
    }
};