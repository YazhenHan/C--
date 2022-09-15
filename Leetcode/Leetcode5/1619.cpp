#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double trimMean(vector<int>& arr) {
        double ans = 0;
        sort(arr.begin(), arr.end());
        for (int i = arr.size() * 0.05; i < arr.size() - arr.size() * 0.05; i++)
            ans += arr[i];
        return ans / (arr.size() - arr.size() * 0.1);
    }
};