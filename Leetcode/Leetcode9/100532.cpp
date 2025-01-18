#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            ans += abs(arr[i] - brr[i]);
        }
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        long long temp = k;
        for (int i = 0; i < arr.size(); i++) {
            temp += abs(arr[i] - brr[i]);
        }
        return min(ans, temp);
    }
};