#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        for (auto& a : A)
            if (a % 2 == 0)
                sum += a;
        vector<int> ans;
        for (auto& query : queries)
        {
            int val = query[0], index = query[1];
            if (A[index] % 2 == 0)
                sum -= A[index];
            A[index] += val;
            if (A[index] % 2 == 0)
                sum += A[index];
            ans.push_back(sum);
        }
        return ans;
    }
};