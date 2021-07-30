#include <vector>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int count = 0;
        for (auto a : arr)
            a == 0 ? count++ : count;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (i + count < arr.size())
            {
                arr[i + count] = arr[i];
            }
            if (arr[i] == 0)
            {
                count--;
                if (i + count < arr.size())
                {
                    arr[i + count] = arr[i];
                }
            }
        }
    }
};