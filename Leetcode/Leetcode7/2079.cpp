#include <vector>

using namespace std;

class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int temp = capacity, ans = 0;
        for (int i = 1; i <= plants.size(); i++) {
            temp -= plants[i - 1];
            if (i < plants.size() && temp < plants[i]) {
                ans += i * 2;
                temp = capacity;
            }
            ans++;
        }
        return ans;
    }
};