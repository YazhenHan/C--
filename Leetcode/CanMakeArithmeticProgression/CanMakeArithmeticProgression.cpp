#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 1; i + 1 < arr.size(); i++)
            if (arr[i] - arr[i-1] != arr[i+1] - arr[i])
                return false;
        return true;
    }
};