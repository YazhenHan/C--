#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        std::vector<std::vector<int>> res;
        for (int i = 0; i < A[0].size(); i++)
        {
            std::vector<int> temp;
            for (int j = 0; j < A.size(); j++)
            {
                temp.push_back(A[j][i]);
            }
            res.push_back(temp);
        }
        return res;
    }
};