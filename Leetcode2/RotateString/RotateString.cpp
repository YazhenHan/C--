#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size())
            return false;
        int j = 0;
        for (int i = 0; i < B.size(); i++)
        {
            while (i < B.size() && B[i] == A[j])
            {
                i++;
                j++;
            }
            if (i == B.size())
            {
                break;
            }
            j = 0;
        }
        if (j == 0)
        {
            return false;
        }
        int i = 0;
        while (j < A.size())
        {
            if (A[j] != B[i])
            {
                return false;
            }
            i++;
            j++;
        }
        return true;
    }
};