#include <vector>

using namespace std;

class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int min = INT32_MAX, max = INT32_MIN;
        for (auto a : A)
        {
            if (a > max)
                max = a;
            if (a < min)
                min = a;
        }
        int ave = (max + min) / 2;
        min = INT32_MAX, max = INT32_MIN;
        for (auto a : A)
        {
            int k = a - ave;
            if (k > K)
                a = a - K;
            else if (k < -K)
                a = a + K;
            else
                a = ave;
            if (a > max)
                max = a;
            if (a < min)
                min = a;
        }
        return max - min;
    }
};