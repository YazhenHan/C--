#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ans;
        for (auto a : A)
            if (a % 2 == 0)
                ans.push_back(a);
        for (auto a : A)
            if (a % 2 != 0)
                ans.push_back(a);
        return ans;
    }
};