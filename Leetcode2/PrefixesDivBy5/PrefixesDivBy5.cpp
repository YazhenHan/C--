#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int num = 0;
        vector<bool> ans;
        for (auto a : A)
        {
            num = num * 2 + a;
            if (num % 5 == 0)
                ans.push_back(true);
            else
                ans.push_back(false);
            num %= 5;
        }
        return ans;
    }
};