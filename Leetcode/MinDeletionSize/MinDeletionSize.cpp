#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int res = 0;
        for (int i = 0; i < A[0].size(); i++)
            for (int j = 0; j + 1 < A.size(); j++)
                if (A[j][i] > A[j+1][i])
                {
                    res++;
                    break;
                }
        return res;
    }
};