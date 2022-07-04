#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int max_abs = INT32_MAX;
        for (int i = 1; i < arr.size(); i++)
            max_abs = min(max_abs, arr[i] - arr[i - 1]);
        for (int i = 1; i < arr.size(); i++)
            if (arr[i] - arr[i - 1] == max_abs)
                ans.push_back({arr[i - 1], arr[i]});
        return ans;
    }
};