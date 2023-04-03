#include <vector>

using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int i = n - 2;
        while (i >= 0) {
            if (arr[i] > arr[i + 1])
                break;
            i--;
        }
        if (i < 0) return arr;
        int t = INT32_MIN, k = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > t && arr[j] < arr[i]) {
                t = arr[j];
                k = j;
            }
        }
        swap(arr[i], arr[k]);
        return arr;
    }
};