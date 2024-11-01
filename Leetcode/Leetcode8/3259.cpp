#include <vector>

using namespace std;

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        long long temp1 = energyDrinkA[0], temp2 = energyDrinkB[0];
        for (int i = 1; i < energyDrinkA.size(); i++) {
            long long temp3 = temp1, temp4 = temp2;
            temp1 = max(temp3 + energyDrinkA[i], temp4);
            temp2 = max(temp4 + energyDrinkB[i], temp3);
        }
        return max(temp1, temp2);
    }
};