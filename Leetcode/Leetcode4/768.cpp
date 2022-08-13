#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> arr2 = arr;
        sort(arr2.begin(), arr2.end());
        unordered_map<int, queue<int>> um;
        for (int i = 0; i < arr2.size(); i++)
            um[arr2[i]].push(i);

        int ans = 0;
        for (int i = 0; i < arr.size();) {
            ans++;
            int temp = um[arr[i]].front();
            um[arr[i]].pop();
            i++;
            while (i <= temp) {
                temp = max(temp, um[arr[i]].front());
                um[arr[i]].pop();
                i++;
            }
        }
        return ans;
    }
};