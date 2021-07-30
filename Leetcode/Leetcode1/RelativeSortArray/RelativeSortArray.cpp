#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> hashArray(1001, 0);
        for (auto ar1 : arr1)
        {
            ++hashArray[ar1];
        }
        vector<int> res;
        for(auto ar2 : arr2) {
            for (int i = 0; i < hashArray[ar2]; i++)
            {
                res.push_back(ar2);
            }
            hashArray[ar2] = 0;
        }
        for (int i = 0; i < hashArray.size(); i++)
        {
            for (int j = 0; j < hashArray[i]; j++)
            {
                res.push_back(i);
            }
            
        }
        return res;
    }
};

int main()
{
}