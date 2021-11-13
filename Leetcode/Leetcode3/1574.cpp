#include <vector>

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        int l = 0, r = 0;
        for (l = 1; l < arr.size(); l++) {
            if (arr[l] < arr[l - 1]) {
                left = arr[l];
                break;
            }
        }
        for (r = arr.size() - 2; r >= 0; r--) {
            if (arr[r] > arr[r + 1]) {
                right = arr[r];
                break;
            }
        }
        if (l - 1 >= r + 1) return 0;
        int ans = arr.size() - 1;
        for (int i = l - 1; i >= -1; i--) {
            for (int j = r + 1; j <= arr.size(); j++) {
                if (i == -1 || j == arr.size() || arr[j] >= arr[i]) {
                    if (ans > j - i - 1)
                        ans = j - i - 1;
                    break;
                }
            }
        }
        return ans;
    }
};