#include <vector>

using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int step = floor(arr.size() * 0.25 + 1);
        for (int i = 0; i + step <= arr.size(); i++)
            if (arr[i + step - 1] == arr[i])
                return arr[i];
        return arr.back();
    }
};