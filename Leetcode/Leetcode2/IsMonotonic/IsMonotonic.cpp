#include <vector>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int flag = A.back() - A[0];
        if (flag == 0)
        {
            for (int i = 1; i < A.size(); i++)
                if (A[i] != A[0])
                    return false;
            return true;
        }
        for (int i = 1; i < A.size(); i++)
            if ((A[i] - A[i - 1]) * flag < 0)
                return false;
        return true;
    }
};