#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans = 0;
        int forRes = INT32_MIN;
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] > forRes)
            {
                forRes = arr[i];
                ans = i;
            }
        return ans;
    }
};