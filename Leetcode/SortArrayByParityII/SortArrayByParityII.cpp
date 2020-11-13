#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        vector<int> res(A.size());
        int odd = 1, even = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] % 2 == 0)
            {
                res[even] = A[i];
                even += 2;
            }
            else
            {
                res[odd] = A[i];
                odd += 2;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> A = {4, 1};
    Solution sol;
    A = sol.sortArrayByParityII(A);
    for (auto &a : A)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}