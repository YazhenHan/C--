#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        for (int i = 0; i < K; i++)
        {
            A[0] = 0 - A[0];
            int temp = A[0];
            int j = 1;
            while (j < A.size())
            {
                if (A[j] < temp)
                    A[j - 1] = A[j];
                else
                    break;
                j++;
            }
            A[j - 1] = temp;
        }
        int res = 0;
        for (auto a : A) 
            res += a;
        return res;
    }
};