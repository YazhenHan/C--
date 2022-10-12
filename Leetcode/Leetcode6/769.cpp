#include <vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            int temp = arr[i];
            for (int j = i; j <= temp; j++) {
                temp = max(temp, arr[j]);
                i = temp;
            }
            ans++;
        }
        return ans;
    }
};