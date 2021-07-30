#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size() || A.size() < 2)
            return false;
        unordered_set<char> uset;
        bool flag = false;
        vector<int> count;
        for (int i = 0; i < A.size(); i++)
        {
            if (uset.find(A[i]) != uset.end())
                flag = true;
            else
                uset.insert(A[i]);
            if (A[i] != B[i])
            {
                count.push_back(i);
                if (count.size() > 2)
                {
                    return false;
                }
            }
        }
        if (count.size() == 1)
        {
            return false;
        }
        if (count.size() == 0)
        {
            if (flag)
                return true;
            else
                return false;
        }
        if (A[count[0]] == B[count[1]] && A[count[1]] == B[count[0]])
        {
            return true;
        }
        return false;
    }
};