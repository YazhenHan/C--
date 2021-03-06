#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0;
        for (int i = A.size() - 1; i - 2 >= 0; i--)
            if (A[i] - A[i - 1] < A[i - 2])
            {
                res = A[i] + A[i - 1] + A[i-2];
                break;
            }
        return res;
    }
};