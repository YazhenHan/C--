#include <vector>

using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<long> v;
        for (long i = 0; i * i <= c; i++)
            v.push_back(i * i);
        long left = 0, right = v.size() - 1;
        while (left <= right) {
            if (v[left] + v[right] == c)
                return true;
            if (v[left] + v[right] < c)
                left++;
            else
                right--;
        }
        return false;
    }
};