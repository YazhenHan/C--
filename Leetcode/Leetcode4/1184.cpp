#include <vector>

using namespace std;

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int ans1 = 0, ans2 = 0;
        for (int i = start; i != destination; i = (i + 1) % distance.size())
            ans1 += distance[i];
        for (int i = start; i != destination; i = (i - 1 + distance.size()) % distance.size())
            ans2 += distance[(i - 1 + distance.size()) % distance.size()];
        return min(ans1, ans2);
    }
};