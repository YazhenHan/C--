#include <vector>

using namespace std;

class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int tempA = capacityA, tempB = capacityB, ans = 0;
        for (int i = 0, j = plants.size() - 1; i <= j; i++, j--) {
            if (i == j) {
                if (tempA < plants[i] && tempB < plants[i])
                    ans++;
                continue;
            }
            if (tempA >= plants[i]) {
                tempA = tempA - plants[i];
            } else {
                ans++;
                tempA = capacityA - plants[i];
            }
            if (tempB >= plants[j]) {
                tempB = tempB - plants[j];
            } else {
                ans++;
                tempB = capacityB - plants[j];
            }
        }
        return ans;
    }
};