#include <vector>

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        vector<bool> flags;
        flags.resize(pieces.size());
        for (auto flag : flags)
            flag = true;
        
        for (int i = 0; i < arr.size();)
        {
            int j = 0;
            for (; j < pieces.size(); j++)
            {
                if (flags[j] && pieces[j][0] == arr[i])
                {
                    i++;
                    for (int k = 1; k < pieces[j].size(); k++,i++)
                    {
                        if (pieces[j][k] != arr[i])
                        {
                            return false;
                        }
                    }
                    flags[j] = false;
                    break;
                }
            }
            if (j == pieces.size())
            {
                return false;
            }
        }
        return true;
    }
};