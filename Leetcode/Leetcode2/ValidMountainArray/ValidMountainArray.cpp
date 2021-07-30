#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3)
            return false;
        int cu = 0, ma = INT32_MIN;
        for (int i = 0; i < arr.size(); i++)
            if (arr[i] >= ma)
            {
                ma = arr[i];
                cu = i;
            }
        if (cu == 0 || cu == arr.size() - 1)
            return false;
        for (int i = cu; i + 1 < arr.size(); i++)
            if (arr[i] <= arr[i + 1])
                return false;
        for (int i = cu; i - 1 >= 0; i--)
            if (arr[i] <= arr[i - 1])
                return false;
        return true;
    }
};